#ifndef __onity_propkind_compold_h__
#define __onity_propkind_compold_h__

#include "EntityTemplate.h"
#include "xui_propkind.h"
#include "xui_kindctrl.h"

//////////////////////////////////////////////////////////////////////////
//propkind
//////////////////////////////////////////////////////////////////////////
class onity_propkind_compold : public xui_propkind
{
public:
	/*
	//constructor
	*/
	onity_propkind_compold( xui_proproot* root, const std::wstring& name, xui_bitmap* icon, BreezeGame::Json::Value* node );

	/*
	//method
	*/
	BreezeGame::Json::Value*	get_node		( void );

protected:
	/*
	//event
	*/
	void						on_namechanged	( xui_component* sender, xui_method_args& args );

	/*
	//member
	*/
	BreezeGame::Json::Value*	m_node;
};

//////////////////////////////////////////////////////////////////////////
//kindctrl
//////////////////////////////////////////////////////////////////////////
class onity_kindctrl_compold : public xui_kindctrl
{
	xui_declare_rtti

public:
	/*
	//static
	*/
	static xui_kindctrl*		create				( xui_propkind* propkind );

	/*
	//constructor
	*/
	onity_kindctrl_compold( xui_propkind* propkind );

protected:
	/*
	//override
	*/
	virtual void				on_perform				( xui_method_args& args );

	/*
	//event
	*/
	void						on_killctrlclick		( xui_component* sender, xui_method_args& args );

	/*
	//member
	*/
	xui_button*					m_killctrl;
};
class onity_kindctrl_compadd : public xui_kindctrl
{
	xui_declare_rtti

public:
	/*
	//static
	*/
	static xui_kindctrl*		create					( xui_propkind* propkind );

	/*
	//constructor
	*/
	onity_kindctrl_compadd( xui_propkind* propkind );

protected:
	/*
	//callback
	*/
	virtual void				on_perform				( xui_method_args& args );

	/*
	//override
	*/
	virtual s32					get_elsectrlsize		( void );
	virtual s32					get_prevctrlsize		( void );

	/*
	//event
	*/
	void						on_menuitemclick		( xui_component* sender, xui_method_args& args );

	/*
	//member
	*/
	xui_toggle*					m_menuctrl;
	xui_textbox*				m_namectrl;
};

#endif//__onity_propkind_compold_h__