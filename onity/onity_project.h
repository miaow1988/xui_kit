#ifndef __onity_project_h__
#define __onity_project_h__

#include "xui_dockpage.h"

enum
{
	FILTER_ALL,
	FILTER_TEXTURE,
	FILTER_MODULE,
	FILTER_SPRITE,
	FILTER_ACTION,
	FILTER_PARTICLE,
	FILTER_CONTROLLER,
};

class onity_fileview;
class onity_propfile;
class onity_proppath;
class onity_project : public xui_dockpage
{
	xui_declare_rtti

public:
	/*
	//constructor
	*/
	onity_project( void );

	/*
	//method
	*/
	void						ini_pathtree		( void );
	void						get_pathfile		( const std::wstring& suff, xui_proproot_vec& filevec );

	/*
	//notify
	*/
	void						ntf_load			( onity_propfile* propfile );
	void						ntf_rename			( const std::wstring& last, const std::wstring& curr );

protected:
	/*
	//event
	*/
	void						on_clearclick		( xui_component* sender, xui_method_args&	  args );
	void						on_searchtextchanged( xui_component* sender, xui_method_args&	  args );
	void						on_filterselection	( xui_component* sender, xui_method_args&	  args );
	void						on_headperform		( xui_component* sender, xui_method_args&	  args );
	void						on_fillperform		( xui_component* sender, xui_method_args&	  args );
	void						on_fillrenderelse	( xui_component* sender, xui_method_args&	  args );
	void						on_sizectrlmousemove( xui_component* sender, xui_method_mouse&	  args );
	void						on_pathviewselection( xui_component* sender, xui_method_args&	  args );
	void						on_folderclick		( xui_component* sender, xui_method_args&	  args );
	void						on_controllerclick	( xui_component* sender, xui_method_args&	  args );
	void						on_pathitemclick	( xui_component* sender, xui_method_args&	  args );
	void						on_pathtogglerender	( xui_component* sender, xui_method_args&	  args );
	void						on_pathtoggleclick	( xui_component* sender, xui_method_args&	  args );
	void						on_sizerollscroll	( xui_component* sender, xui_method_args&	  args );
	void						on_fileviewnodeclick( xui_component* sender, xui_method_mouse&	  args );
	void						on_fileviewdoubleclk( xui_component* sender, xui_method_mouse&	  args );
	void						on_fileviewassetdrag( xui_component* sender, xui_method_dragdrop& args );
	void						on_freetypeclick	( xui_component* sender, xui_method_args&	  args );
	void						on_loadtypeclick	( xui_component* sender, xui_method_args&	  args );
	void						on_showfindclick	( xui_component* sender, xui_method_args&	  args );
	void						on_propertyclick	( xui_component* sender, xui_method_args&	  args );
	void						on_pathtoolclick	( xui_component* sender, xui_method_args&	  args );

	/*
	//method
	*/
	void						refresh_fileview	( void );
	void						refresh_pathpane	( void );
	void						refresh_pathtool	( void );
	void						refresh_tileview	( void );
	std::wstring				convert_filesuff	( void );
	void						set_freetype		( u08 type, const std::string& pathname, u32 style );
	void						set_loadtype		( u08 type, const std::string& pathname, bool flag );

	/*
	//member
	*/
	xui_panel*					m_head;
	xui_toggle*					m_create;
	xui_menuitem*				m_folder;
	xui_menuitem*				m_controller;
	xui_textbox*				m_search;
	xui_button*					m_clear;

	xui_panel*					m_fill;
	xui_control*				m_sizectrl;
	xui_treeview*				m_pathview;
	onity_fileview*				m_fileview;
	xui_button*					m_backpath;
	xui_button*					m_forepath;
	xui_panel*					m_pathpane;
	xui_panel*					m_toolpane;
	xui_slider*					m_sizeroll;
	xui_linebox*				m_browse;
	xui_dropbox*				m_filter;
	xui_drawer*					m_status;

	xui_menuitem*				m_showfind;
	xui_menuitem*				m_loadtype;
	xui_menuitem*				m_freetype;
	xui_menuitem*				m_property;
	xui_menuitem*				m_auto;
	xui_menuitem*				m_never;
	xui_menuitem*				m_immediate;
	xui_menuitem*				m_on;
	xui_menuitem*				m_off;

	std::vector<xui_treenode*>	m_histroy;
	s32							m_curridx;
};

#endif//__onity_project_h__