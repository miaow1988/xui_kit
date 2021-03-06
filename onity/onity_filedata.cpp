#include "xui_global.h"
#include "xui_treenode.h"
#include "xui_proproot.h"
#include "xui_kindctrl.h"
#include "onity_project.h"
#include "onity_mainform.h"
#include "onity_resource.h"
#include "onity_propfile.h"
#include "onity_filedata.h"

/*
//constructor
*/
xui_create_explain(onity_filedata)( xui_bitmap* icon, const std::wstring& full, xui_proproot* prop )
: onity_treedata(icon, prop)
{
	m_text = full;
}

/*
//method
*/
xui_method_explain(onity_filedata, get_path,		std::wstring		)( void ) const
{
	return get_path(m_text);
}
xui_method_explain(onity_filedata, get_file,		std::wstring		)( void ) const
{
	return get_file(m_text);
}
xui_method_explain(onity_filedata, get_suff,		std::wstring		)( void ) const
{
	return get_suff(m_text);
}
xui_method_explain(onity_filedata, get_full,		const std::wstring&	)( void ) const
{
	return m_text;
}
xui_method_explain(onity_filedata, set_full,		void				)( const std::wstring& full )
{
	m_text = full;
	m_node->use_linkdata();
}

/*
//override
*/
xui_method_explain(onity_filedata, get_icon,		xui_bitmap*			)( u32 index )
{
	if (m_text == L"None")
		return NULL;

	return m_icon;
}
xui_method_explain(onity_filedata, get_text,		std::wstring		)( u32 index )
{
	return get_safe(m_text);
}
xui_method_explain(onity_filedata, set_text,		void				)( u32 index, const std::wstring& text )
{
	onity_propfile* propfile = dynamic_cast<onity_propfile*>(m_prop);
	if (propfile && propfile->can_rename() == false)
		return;

	xui_global::set_fwatchclose();
	std::wstring suff = get_suff();
	std::wstring curr = get_path()+text+suff;
	std::wstring last = m_text;
	if (xui_global::rna_file(last, curr))
	{
		ntf_rename(last, curr);
		onity_project* project = onity_mainform::get_ptr()->get_project();
		project->ntf_rename(last, curr);
	}
	xui_global::set_fwatchstart(xui_global::get_workpath());
}

/*
//virtual
*/
xui_method_explain(onity_filedata, ntf_rename,		void				)( const std::wstring& last, const std::wstring& curr )
{
	int npos = m_text.find(last);
	m_text.replace(npos, last.length(), curr);
	m_node->use_linkdata();

	onity_propfile* propfile = dynamic_cast<onity_propfile*>(m_prop);
	if (propfile)
		propfile->ntf_rename(last, curr);
}

/*
//static
*/
xui_method_explain(onity_filedata, get_path,		std::wstring		)( const std::wstring& full )
{
	std::wstring  temp = full;

	int index  = temp.find_last_of(L'/');
	if (index == -1)
		index  = temp.find_last_of(L'\\');
	if (index == -1)
		return L"";

	return temp.erase(index+1);
}
xui_method_explain(onity_filedata, get_file,		std::wstring		)( const std::wstring& full )
{
	std::wstring temp = full;

	int npos  = temp.find_last_of(L'/');
	if (npos == -1)
		npos  = temp.find_last_of(L'\\');
	if (npos != -1)
		temp.erase(0, npos+1);

	return temp;
}
xui_method_explain(onity_filedata, get_suff,		std::wstring		)( const std::wstring& full )
{
	std::wstring temp = full;
	int npos  = temp.find_last_of('.');
	if (npos == -1)
		temp = L"";
	else
		temp.erase(0, npos);

	if (temp == L".PNG" || temp == L".Png")
		temp =  L".png";

	return temp;
}
xui_method_explain(onity_filedata, get_safe,		std::wstring		)( const std::wstring& full )
{
	std::wstring temp = get_file(full);

	int npos  = temp.find_last_of(L'.');
	if (npos != -1)
		temp.erase(npos);

	return temp;
}