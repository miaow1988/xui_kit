#ifndef __onity_propactor_h__
#define __onity_propactor_h__

#include "onity_prop2dsasset.h"

class onity_propactor : public onity_prop2dsasset
{
public:
	/*
	//constructor
	*/
	onity_propactor( onity_propfile* propfile, u32 id );

	/*
	//method
	*/
	const xui_proproot_vec&		get_colliders	( void ) const;
	void						add_collider	( void );
	void						del_collider	( xui_proproot* proproot );

protected:
	/*
	//static
	*/
	static bool					was_loop		( void* userptr );
	static void					set_loop		( void* userptr, bool value );
	static f64					get_loopstart	( void* userptr );
	static void					set_loopstart	( void* userptr, f64  value );
	static xui_proproot_vec		get_colliders	( void* userptr );
	static void					add_collider	( void* userptr );
	static void					del_collider	( void* userptr, xui_proproot* proproot );

	/*
	//member
	*/
	xui_propkind*				m_actorkind;
	xui_proproot_vec			m_propcolliders;
};

#endif//__onity_propactor_h__