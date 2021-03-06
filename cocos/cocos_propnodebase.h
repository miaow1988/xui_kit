#ifndef __cocos_propnodebase_h__
#define __cocos_propnodebase_h__

#include "cocos_proproot.h"
#include "cocos_propdata_unitvec.h"

namespace cocos2d
{
	class Node;
	class Sprite;
}

class cocos_propcsd;
class cocos_boundbox;
class cocos_propnodebase : public cocos_proproot
{
public:
	/*
	//constructor
	*/
	cocos_propnodebase( xui_bitmap* icon, cocos_propcsd* file, cocos2d::Node* node );

	/*
	//destructor
	*/
	virtual ~cocos_propnodebase( void );

	/*
	//method
	*/
	xui_bitmap*					get_icon		( void );
	cocos_propcsd*				get_file		( void );
	cocos2d::Node*				get_node		( void );
	cocos_boundbox*				get_boundbox	( void );
	const xui_proproot_vec&		get_leafprop	( void ) const;
	void						del_propnode	( cocos_propnodebase* prop );
	void						add_propnode	( cocos_propnodebase* prop, u32 index = -1 );

	/*
	//static
	*/
	static std::wstring			get_path		( u08 type );
	static std::wstring			get_type		( cocos2d::Node* node );
	static cocos_propnodebase*	new_prop		( cocos_propcsd* file, cocos2d::Node* node );
	static cocos_propnodebase*	new_prop		( cocos_propcsd* file, const std::wstring& rtti );

protected:
	/*
	//method
	*/
	void						add_title		( void );
	void						add_location	( void );
	void						add_anchor		( void );
	void						add_position	( void );
	void						add_size		( bool editsize, cocos_propdata_unitvec::get_func def_func );
	void						add_aligndock	( bool editsize );
	void						add_base		( void );
	void						add_common		( void );
	void						add_color		( void );
	void						add_flip		( void );
	void						add_special		( void );
	void						add_advance		( void );
	void						add_userdata	( void );

	/*
	//static
	*/
	static std::wstring			get_name		( void* userptr );
	static void					set_name		( void* userptr, const std::wstring& value );

	static xui_vector<f64>		get_anchor		( void* userptr );
	static void					set_anchor		( void* userptr, const xui_vector<f64>& value );
	static cocos_value_unitvec	get_position	( void* userptr );
	static void					set_position	( void* userptr, const cocos_value_unitvec& value );
	static cocos_value_unitvec	get_size		( void* userptr );
	static void					set_size		( void* userptr, const cocos_value_unitvec& value );

	static bool					was_visible		( void* userptr );
	static void					set_visible		( void* userptr, bool value );
	static f64					get_tag			( void* userptr );
	static void					set_tag			( void* userptr, f64  value );
	static xui_vector<f64>		get_scale		( void* userptr );
	static void					set_scale		( void* userptr, const xui_vector<f64>& value );
	static f64					get_rotation	( void* userptr );
	static void					set_rotation	( void* userptr, f64  value );
	static xui_vector<f64>		get_bias		( void* userptr );
	static void					set_bias		( void* userptr, const xui_vector<f64>& value );
	static f64					get_zorder		( void* userptr );
	static void					set_zorder		( void* userptr, f64  value );
	static xui_colour			get_color		( void* userptr );
	static void					set_color		( void* userptr, const xui_colour& value );
	static f64					get_alpha		( void* userptr );
	static void					set_alpha		( void* userptr, f64 value );

	static std::wstring			get_userdata	( void* userptr );
	static void					set_userdata	( void* userptr, const std::wstring& value );

	/*
	//default
	*/
	static cocos2d::Node*		def_particle	( void );
	static cocos2d::Node*		def_sprite		( void );
	static cocos2d::Node*		def_node		( void );
	static cocos2d::Node*		def_button		( void );
	static cocos2d::Node*		def_checkbox	( void );
	static cocos2d::Node*		def_imageview	( void );
	static cocos2d::Node*		def_text		( void );
	static cocos2d::Node*		def_textbmfont	( void );
	static cocos2d::Node*		def_loadingbar	( void );
	static cocos2d::Node*		def_slider		( void );
	static cocos2d::Node*		def_textfield	( void );
	static cocos2d::Node*		def_layout		( void );
	static cocos2d::Node*		def_scrollview	( void );
	static cocos2d::Node*		def_listview	( void );
	static cocos2d::Node*		def_pageview	( void );
	static cocos2d::Node*		def_layoutcenter( void );
	static cocos2d::Node*		def_adapternode	( void );
	static cocos2d::Node*		def_shaderrect	( void );
	static cocos2d::Node*		def_textifbm	( void );
	static cocos2d::Node*		def_weclabel	( void );
	static cocos2d::Node*		def_spinenode	( void );
	static cocos2d::Node*		def_spineblender( void );
	static cocos2d::Node*		def_object3d	( void );
	static cocos2d::Node*		def_node3dobject( void );

	/*
	//helper
	*/
	static void*				get_image		( cocos2d::Sprite* sprite );
	static void					set_image		( cocos2d::Sprite* sprite, void* value );

	/*
	//event
	*/
	virtual void				on_propchanged	( xui_component* sender, xui_method_propdata& args );

	/*
	//member
	*/
	cocos_propcsd*				m_file;
	xui_bitmap*					m_icon;
	cocos2d::Node*				m_node;
	xui_proproot_vec			m_leafprop;
	cocos_boundbox*				m_boundbox;
};

#endif//__cocos_propnodebase_h__