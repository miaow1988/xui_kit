#include "NP2DSActor.h"
#include "NP2DSActorFile.h"
#include "NP2DSState.h"
#include "NP2DSStateCtrl.h"
#include "NP2DSTransition.h"

#include "xui_global.h"
#include "xui_textbox.h"
#include "xui_propkind.h"
#include "xui_kindctrl.h"
#include "xui_propdata.h"
#include "xui_propctrl.h"
#include "xui_propctrl_object.h"
#include "onity_resource.h"
#include "onity_state.h"
#include "onity_savekind.h"
#include "onity_propctrl_transition.h"
#include "onity_proptransition.h"
#include "onity_propcontroller.h"
#include "onity_propstate.h"
#include "onity_propctrl_transref.h"

#include "onity_mainform.h"
#include "onity_animator.h"

/*
//constructor
*/
xui_create_explain(onity_propstate)( onity_propfile* propfile, onity_state* statectrl )
: onity_propleaf(propfile)
, m_statectrl(statectrl)
{
	NP2DSState* state = m_statectrl->get_state();
	const NP2DSState::TransitionVec& vec = state->GetTransitionVec();
	for (u32 i = 0; i < vec.size(); ++i)
	{
		m_proptransition.push_back(new onity_proptransition(propfile, vec[i]));
	}

	m_statekind		= new xui_propkind(this, xui_global::ascii_to_unicode(state->GetName()), "State", xui_kindctrl::create, onity_resource::icon_state, true);
	xui_method_ptrcall(m_statekind, xm_namechanged) += new xui_method_member<xui_method_args,     onity_propstate>(this, &onity_propstate::on_namechanged);
	m_retarget		= new xui_propdata_bool(
		m_statekind, 
		L"Retarget", 
		xui_propctrl_bool::create, 
		get_retarget, 
		set_retarget, 
		state);
	m_actor			= new onity_propdata_2dsasset(
		m_statekind, 
		L"Action", 
		onity_propctrl_asset::create,
		DROPTYPE_ACTOR, 
		get_actor, 
		set_actor, 
		state);

	m_transition	= new xui_propdata_stdvec_root(
		m_statekind,
		L"Transitions",
		onity_propctrl_transition::create,
		NULL, 
		del_transition,
		get_transitions,
		this);

	m_statekind->add_propdata(m_retarget);
	m_statekind->add_propdata(m_actor);
	m_statekind->add_propdata(m_transition);
	add_propkind(m_statekind);
}

/*
//destructor
*/
xui_delete_explain(onity_propstate)( void )
{
	for (u32 i = 0; i < m_proptransition.size(); ++i)
		delete m_proptransition[i];

	m_proptransition.clear();
}

/*
//method
*/
xui_method_explain(onity_propstate,	get_statectrl,		onity_state*			)( void )
{
	return m_statectrl;
}
xui_method_explain(onity_propstate, get_proptransitions,const xui_proproot_vec&	)( void ) const
{
	return m_proptransition;
}
xui_method_explain(onity_propstate, get_proptransition,	onity_proptransition*	)( NP2DSTransition* transition )
{
	for (u32 i = 0; i < m_proptransition.size(); ++i)
	{
		onity_proptransition* proptransition = dynamic_cast<onity_proptransition*>(m_proptransition[i]);
		if (proptransition->get_transition() == transition)
			return proptransition;
	}

	return NULL;
}
xui_method_explain(onity_propstate, add_transition,		void					)( NP2DSTransition* transition )
{
	m_proptransition.push_back(new onity_proptransition(m_savekind->get_propfile(), transition));
	m_transition->refresh();
}
xui_method_explain(onity_propstate, del_transition,		void					)( NP2DSTransition* transition )
{
	for (u32 i = 0; i < m_proptransition.size(); ++i)
	{
		onity_proptransition* proptransition = dynamic_cast<onity_proptransition*>(m_proptransition[i]);
		if (proptransition->get_transition() == transition)
		{
			delete proptransition;
			m_proptransition.erase(m_proptransition.begin()+i);
			break;
		}
	}

	m_transition->refresh();
}
xui_method_explain(onity_propstate, on_delstate,		void					)( NP2DSState* state )
{
	onity_propctrl_transition* propctrl = xui_dynamic_cast(onity_propctrl_transition, m_transition->get_ctrl());
	if (propctrl && propctrl->has_propdata(m_transition))
	{
		propctrl->on_delstate(state);
	}

	for (s32 i = (s32)m_proptransition.size()-1; i >= 0; --i)
	{
		onity_proptransition* proptransition = dynamic_cast<onity_proptransition*>(m_proptransition[i]);
		if (proptransition->get_transition()->GetNextState() == state)
		{
			delete proptransition;
			m_proptransition.erase(m_proptransition.begin()+i);
		}
	}
}
xui_method_explain(onity_propstate, on_delparam,		void					)( NP2DSParam* param )
{
	for (u32 i = 0; i < m_proptransition.size(); ++i)
	{
		onity_proptransition* proptransition = dynamic_cast<onity_proptransition*>(m_proptransition[i]);
		proptransition->on_delparam(param);
	}
}
xui_method_explain(onity_propstate, on_addparam,		void					)( NP2DSParam* param )
{
	for (u32 i = 0; i < m_proptransition.size(); ++i)
	{
		onity_proptransition* proptransition = dynamic_cast<onity_proptransition*>(m_proptransition[i]);
		proptransition->on_addparam(param);
	}
}

/*
//event
*/
xui_method_explain(onity_propstate, on_namechanged,		void					)( xui_component* sender, xui_method_args& args )
{
	xui_textbox* textbox = xui_dynamic_cast(xui_textbox, sender);
	std::wstring text = textbox->get_text();
	std::string  name = xui_global::unicode_to_ascii(text);

	bool has_same = false;
	NP2DSStateCtrl* editfile = m_statectrl->get_state()->GetStateCtrl();
	const NP2DSStateCtrl::StateVec& vec = editfile->GetStateVec();
	for (u32 i = 0; i < vec.size(); ++i)
	{
		if (vec[i] != m_statectrl->get_state() && vec[i]->GetName() == name)
		{
			has_same = true;
			break;
		}
	}

	if (has_same || name.length() == 0)
	{
		s32 number = 0;
		while (true)
		{
			std::stringstream temp;
			temp << ((name.length() == 0) ? "New State" : name.c_str());
			temp << number;

			has_same = false;
			for (u32 i = 0; i < vec.size(); ++i)
			{
				if (vec[i] != m_statectrl->get_state() && vec[i]->GetName() == temp.str())
				{
					has_same = true;
					break;
				}
			}

			if (has_same == false)
			{
				name = temp.str();
				text = xui_global::ascii_to_unicode(name);
				textbox->ini_textbox(text);
				break;
			}

			++number;
		}
	}

	if (m_statectrl->get_state()->GetName() != name)
	{
		m_statekind->set_name(text);
		m_statectrl->set_text(text);
		m_statectrl->get_state()->SetName(name);
		m_statectrl->get_state()->GetStateCtrl()->SetNeedSave(true);
	}
}

/*
//static
*/
xui_method_explain(onity_propstate, get_retarget,		bool					)( void* userptr )
{
	NP2DSState* state = (NP2DSState*)userptr;
	return state->CanRetarget();
}
xui_method_explain(onity_propstate, set_retarget,		void					)( void* userptr, bool  value )
{
	NP2DSState* state = (NP2DSState*)userptr;
	state->SetRetarget(value);
}
xui_method_explain(onity_propstate, get_actor,			void*					)( void* userptr )
{
	NP2DSState* state = (NP2DSState*)userptr;
	return state->GetActor();
}
xui_method_explain(onity_propstate, set_actor,			void					)( void* userptr, void* value )
{
	NP2DSState* state = (NP2DSState*)userptr;
	NP2DSActor* actor = (NP2DSActor*)value;
	npu32 resfile = (actor == NULL) ? -1 : actor->GetOwnedFile()->GetKey();
	npu32 actorid = (actor == NULL) ? -1 : actor->GetKey();
	state->SetActor(resfile, actorid);
}
xui_method_explain(onity_propstate, get_transitions,	xui_proproot_vec		)( void* userptr )
{
	onity_propstate* propstate = (onity_propstate*)userptr;
	return propstate->get_proptransitions();
}
xui_method_explain(onity_propstate, del_transition,		void					)( void* userptr, xui_proproot* root )
{
	onity_propstate*		propstate		= (onity_propstate*)userptr;
	onity_state*			statectrl		= propstate->get_statectrl();
	onity_proptransition*	proptransition	= dynamic_cast<onity_proptransition*>(root);
	NP2DSTransition*		transition		= proptransition->get_transition();

	propstate->del_transition(transition);
	statectrl->get_state()->DelTransition(transition);
}