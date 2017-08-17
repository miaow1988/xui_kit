#include "2d/CCSprite.h"
#include "2d/CCSpriteFrame.h"

#include "xui_global.h"
#include "xui_kindctrl.h"
#include "cocos_resource.h"
#include "cocos_filedata.h"
#include "cocos_mainform.h"
#include "cocos_propatlas.h"
#include "cocos_propframe.h"
#include "cocos_propdata_image.h"
#include "cocos_propctrl_flip.h"
#include "cocos_project.h"
#include "cocos_propnodesprite.h"

/*
//constructor
*/
xui_create_explain(cocos_propnodesprite)( cocos_propcsd* file, cocos2d::Node* node )
: cocos_propnodebase(cocos_resource::icon_animator, file, node)
, m_sprite(dynamic_cast<cocos2d::Sprite*>(node))
{
	add_location	();
	add_anchor		();
	add_position	();
	add_size		(false, NULL);
	add_aligndock	(false);
	add_base		();
	add_common		();
	add_color		();
	add_flip		();
	add_special		();
	add_image		();
	add_advance		();
	add_userdata	();
}

/*
//method
*/
xui_method_explain(cocos_propnodesprite, get_sprite,	cocos2d::Sprite*	)( void )
{
	return m_sprite;
}

/*
//method
*/
xui_method_explain(cocos_propnodesprite, add_image,		void				)( void )
{
	xui_propkind* kind = new xui_propkind(this, L"", "NodeSprite", xui_kindctrl::create, m_icon, true, false);
	kind->xm_propchanged += new xui_method_member<xui_method_propdata, cocos_propnodesprite>(this, &cocos_propnodesprite::on_propchanged);
	kind->add_propdata(new cocos_propdata_image(
		kind,
		L"Image",
		get_image,
		set_image,
		this));
	kind->add_propdata(new cocos_propdata_blend(
		kind,
		get_blendfunc,
		set_blendfunc,
		this));

	add_propkind(kind);
}
xui_method_explain(cocos_propnodesprite, add_flip,		void				)( void )
{
	xui_propkind* kind = new xui_propkind(this, L"", "NodeFlip", xui_kindctrl::create, m_icon, true, false);
	kind->xm_propchanged += new xui_method_member<xui_method_propdata, cocos_propnodesprite>(this, &cocos_propnodesprite::on_propchanged);
	kind->add_propdata(new cocos_propdata_flip(kind, this));
	add_propkind(kind);
}

/*
//static
*/
xui_method_explain(cocos_propnodesprite, get_image,		void*				)( void* userptr )
{
	cocos_propnodesprite*	prop	= (cocos_propnodesprite*)userptr;
	cocos2d::Sprite*		sprite	= prop->get_sprite();
	cocos2d::SpriteFrame*	frame	= sprite->getSpriteFrame();
	if (frame->getName().length() > 0)
		return frame;
	else
		return sprite->getTexture();
}
xui_method_explain(cocos_propnodesprite, set_image,		void				)( void* userptr, void* value )
{
	cocos2d::Ref*			base	= (cocos2d::Ref*)value;
	cocos2d::Texture2D*		texture = dynamic_cast<cocos2d::Texture2D*	>(base);
	cocos2d::SpriteFrame*	frame	= dynamic_cast<cocos2d::SpriteFrame*>(base);

	cocos_propnodesprite*	prop	= (cocos_propnodesprite*)userptr;
	cocos2d::Sprite*		sprite	= prop->get_sprite();
	if (frame)
	{
		sprite->setSpriteFrame(frame);
	}
	else
	if (texture)
	{
		sprite->initWithTexture(texture);
	}
	else
	{
		sprite->init();
	}
}
xui_method_explain(cocos_propnodesprite, get_blendfunc, cocos_blend_value	)( void* userptr )
{
	cocos_propnodesprite* prop = (cocos_propnodesprite*)userptr;
	cocos2d::Sprite* sprite = prop->get_sprite();
	cocos2d::BlendFunc func = sprite->getBlendFunc();
	return cocos_blend_value(func.src, func.dst);
}
xui_method_explain(cocos_propnodesprite, set_blendfunc, void				)( void* userptr, const cocos_blend_value& value )
{
	cocos_propnodesprite* prop = (cocos_propnodesprite*)userptr;
	cocos2d::Sprite* sprite = prop->get_sprite();
	cocos2d::BlendFunc func;
	func.src = value.src;
	func.dst = value.dst;
	sprite->setBlendFunc(func);
}
//xui_method_explain(cocos_propnodesprite, def_size,		cocos_value_unitvec )( void* userptr )
//{
//	cocos_value_unitvec value;
//
//	cocos_propnodesprite* prop = (cocos_propnodesprite*)userptr;
//	cocos2d::SpriteFrame* frame = prop->get_sprite()->getSpriteFrame();
//	if (frame)
//	{
//		cocos2d::Size size = frame->getOriginalSize();
//		value.w.pix = size.width;
//		value.h.pix = size.height;
//	}
//
//	return value;
//}