#include "xui_desktop.h"
#include "xui_scroll.h"
#include "xui_scrollthumb.h"

xui_implement_rtti(xui_scrollthumb, xui_button);

/*
//constructor
*/
xui_create_explain(xui_scrollthumb)( const xui_vector<s32>& size, u08 flowstyle )
: xui_button(size)
{
	m_mouserela = xui_vector<s32>(0);
	m_flowstyle	= flowstyle;
}

/*
//callback
*/
xui_method_explain(xui_scrollthumb, on_mousedown,	void)( xui_method_mouse& args )
{
	xui_button::on_mousedown(args);
	if (args.mouse == MB_L)
	{
		m_mouserela = get_renderpt(args.point);

		xui_scroll* scroll = xui_dynamic_cast(xui_scroll, m_parent);
		scroll->get_valueaction()->clear();
	}
}
xui_method_explain(xui_scrollthumb, on_mousemove,	void)( xui_method_mouse& args )
{
	xui_button::on_mousemove(args);
	if (has_catch())
	{
		xui_scroll* scroll = xui_dynamic_cast(xui_scroll, m_parent);
		xui_rect2d<s32> rt = scroll->get_hallowrt();
		xui_vector<s32> pt = xui_desktop::get_ins()->get_mousecurr() - m_mouserela;
		switch (m_flowstyle)
		{
		case FLOWSTYLE_H:
			{
				//限制滚轮的位置
				s32 x = m_parent->get_renderpt(pt).x;
				if (x < rt.ax)
					x = rt.ax;
				if (x > rt.bx-get_renderw())
					x = rt.bx-get_renderw();

				on_perform_x(x);
			}
			break;
		case FLOWSTYLE_V:
			{
				//限制滚轮的位置
				s32 y = m_parent->get_renderpt(pt).y;
				if (y < rt.ay)
					y = rt.ay;
				if (y > rt.by-get_renderh())
					y = rt.by-get_renderh();

				on_perform_y(y);
			}
			break;
		}

		scroll->update_value();
	}
}
xui_method_explain(xui_scrollthumb, on_mouserise,	void)( xui_method_mouse& args )
{
	xui_button::on_mouserise(args);
	if (args.mouse == MB_L)
	{
		xui_scroll* scroll = xui_dynamic_cast(xui_scroll, m_parent);
		scroll->update_thumb();
	}
}