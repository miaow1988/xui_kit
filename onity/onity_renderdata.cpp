#include "NP2DSImageRef.h"
#include "NP2DSFrameRef.h"
#include "NP2DSActorRef.h"
#include "NPParticleSFX.h"
#include "onity_propnoderender.h"
#include "onity_renderdata.h"

/*
//constructor
*/
xui_create_explain(onity_renderdata)( xui_proproot* prop )
: onity_treedata(NULL, prop)
{}

/*
//destructor
*/
xui_delete_explain(onity_renderdata)( void )
{
	if (m_prop)
	{
		delete m_prop;
		m_prop = NULL;
	}
}

/*
//override
*/
xui_method_explain(onity_renderdata, get_text, std::wstring	)( u32 index )
{
	onity_propnoderender* prop = dynamic_cast<onity_propnoderender*>(m_prop);
	NPNode* node = prop->get_node();
	if		(NPIsExaKindOf(NP2DSTransRef, node)) return L"Container";
	else if	(NPIsSubKindOf(NP2DSImageRef, node)) return L"Module";
	else if (NPIsSubKindOf(NP2DSFrameRef, node)) return L"Sprite";
	else if (NPIsSubKindOf(NP2DSActorRef, node)) return L"Action";
	else if (NPIsExaKindOf(NPParticleSFX, node)) return L"Particle";
	{
		return L"Node";
	}
}
xui_method_explain(onity_renderdata, get_flag, bool			)( u32 index )
{
	onity_propnoderender* prop = dynamic_cast<onity_propnoderender*>(m_prop);
	return prop->get_node()->WasVisible();
}
xui_method_explain(onity_renderdata, set_flag, void			)( u32 index, bool flag )
{
	onity_propnoderender* prop = dynamic_cast<onity_propnoderender*>(m_prop);
	prop->get_node()->SetVisible(flag);
}