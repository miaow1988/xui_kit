#include "xui_component.h"
#include "xui_timermgr.h"
#include "xui_timer.h"

/*
//constructor
*/
xui_create_explain(xui_timer)( xui_component* owner, f32 interval, void* data )
{
	m_owner		= owner;
	m_enable	= true;
	m_interval	= interval;
	m_data		= data;
	m_time		= 0.0f;
}

/*
//property
*/
xui_method_explain(xui_timer, was_enable,	bool	)( void ) const
{
	return m_enable;
}
xui_method_explain(xui_timer, set_enable,	void	)( bool flag )
{
	if (m_enable != flag)
	{
		m_enable  = flag;
		reset();
	}
}
xui_method_explain(xui_timer, get_interval,	f32		)( void ) const
{
	return m_interval;
}
xui_method_explain(xui_timer, set_interval,	void	)( f32 interval )
{
	m_interval = interval;
}
xui_method_explain(xui_timer, get_data,		void*	)( void ) const
{
	return m_data;
}
xui_method_explain(xui_timer, set_data,		void	)( void* data )
{
	m_data = data;
}

/*
//method
*/
xui_method_explain(xui_timer, update,		void	)( f32 delta )
{
	if (m_enable)
	{
		m_time += delta;
		if (m_time >= m_interval)
		{
			m_time -= m_interval;

			xui_method_args  args;
			xm_tick(m_owner, args);
		}
	}
}
xui_method_explain(xui_timer, reset,		void	)( void )
{
	m_time = 0.0f;
}