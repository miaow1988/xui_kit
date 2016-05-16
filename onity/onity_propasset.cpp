#include "xui_kindctrl.h"
#include "xui_dialog.h"
#include "xui_desktop.h"
#include "onity_savekind.h"
#include "onity_propfile.h"
#include "onity_propasset.h"

/*
//constructor
*/
xui_create_explain(onity_propasset)( onity_propfile* propfile )
: xui_proproot()
{
	m_savekind = new onity_savekind(this, propfile);
	add_propkind(m_savekind);
}

/*
//method
*/
xui_method_explain(onity_propasset, get_propfile,	onity_propfile*	)( void )
{
	return m_savekind->get_propfile();
}

/*
//override
*/
xui_method_explain(onity_propasset, on_detach,		void			)( const xui_proproot_vec& proproot )
{
	onity_propfile* selffile = get_propfile();
	if (selffile->was_modify())
	{
		bool notify = true;
		for (u32 i = 0; i < proproot.size(); ++i)
		{
			onity_propfile* propfile = dynamic_cast<onity_propfile*>(proproot[i]);
			if (propfile == NULL)
			{
				onity_propasset* propasset = dynamic_cast<onity_propasset*>(proproot[i]);
				if (propasset)
					propfile = propasset->get_propfile();
			}

			if (propfile && propfile == selffile)
			{
				notify = false;
				break;
			}
		}

		if (notify)
		{
			std::wstringstream text;
			text << L"Asset file has Changed.\n\'";
			text << selffile->get_full().c_str();
			text << L"\'\n";
			xui_dialog* dialog = (xui_dialog*)xui_desktop::get_ins()->show_message(text.str(), 2);
			dialog->set_text(0, L"Apply" );
			dialog->set_text(1, L"Revert");
			dialog->set_data(selffile);
			dialog->xm_accept += new xui_method_static<xui_method_args>(onity_propfile::on_notify_accept);
			dialog->xm_cancel += new xui_method_static<xui_method_args>(onity_propfile::on_notify_cancel);
		}
	}
}