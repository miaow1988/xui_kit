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
	//static
	*/
	static f64					get_number		( void* userptr );
	static void					set_number		( void* userptr, f64  value );
	static bool					get_bool		( void* userptr );
	static void					set_bool		( void* userptr, bool value );
	static std::wstring			get_string		( void* userptr );
	static void					set_string		( void* userptr, const std::wstring& value );

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
	static xui_kindctrl*		create			( xui_propkind* propkind );

	/*
	//constructor
	*/
	onity_kindctrl_compold( xui_propkind* propkind );

protected:
	/*
	//override
	*/
	virtual void				set_propkindimpl( void );
};

#endif//__onity_propkind_compold_h__