#include "xui_global.h"
#include "xui_component.h"
#include "cocos_resource.h"

xui_bitmap* cocos_resource::icon_pickcolour	= NULL;
xui_bitmap* cocos_resource::icon_pickselect = NULL;
xui_bitmap* cocos_resource::icon_loop		= NULL;
xui_bitmap*	cocos_resource::icon_animator	= NULL;
xui_bitmap*	cocos_resource::icon_bigerror	= NULL;
xui_bitmap*	cocos_resource::icon_bigmessage	= NULL;
xui_bitmap*	cocos_resource::icon_bigwarning	= NULL;
xui_bitmap*	cocos_resource::icon_center		= NULL;
xui_bitmap*	cocos_resource::icon_clear		= NULL;
xui_bitmap*	cocos_resource::icon_console	= NULL;
xui_bitmap*	cocos_resource::icon_delete		= NULL;
xui_bitmap*	cocos_resource::icon_error		= NULL;
xui_bitmap*	cocos_resource::icon_file		= NULL;
xui_bitmap*	cocos_resource::icon_folder		= NULL;
xui_bitmap*	cocos_resource::icon_game		= NULL;
xui_bitmap*	cocos_resource::icon_hierarchy	= NULL;
xui_bitmap*	cocos_resource::icon_inspector	= NULL;
xui_bitmap*	cocos_resource::icon_local		= NULL;
xui_bitmap*	cocos_resource::icon_message	= NULL;
xui_bitmap*	cocos_resource::icon_pivot		= NULL;
xui_bitmap*	cocos_resource::icon_project	= NULL;
xui_bitmap*	cocos_resource::icon_rotation	= NULL;
xui_bitmap*	cocos_resource::icon_scale		= NULL;
xui_bitmap*	cocos_resource::icon_scene		= NULL;
xui_bitmap*	cocos_resource::icon_search		= NULL;
xui_bitmap*	cocos_resource::icon_select		= NULL;
xui_bitmap*	cocos_resource::icon_timeline	= NULL;
xui_bitmap*	cocos_resource::icon_translate	= NULL;
xui_bitmap*	cocos_resource::icon_warning	= NULL;
xui_bitmap*	cocos_resource::icon_world		= NULL;
xui_bitmap* cocos_resource::icon_state		= NULL;
xui_bitmap* cocos_resource::icon_transition = NULL;
xui_bitmap* cocos_resource::icon_leftright	= NULL;
xui_bitmap* cocos_resource::icon_topbottom	= NULL;
xui_bitmap* cocos_resource::icon_large		= NULL;
xui_bitmap* cocos_resource::icon_small		= NULL;
xui_bitmap* cocos_resource::icon_reset		= NULL;
xui_bitmap* cocos_resource::icon_play		= NULL;
xui_bitmap* cocos_resource::icon_back		= NULL;
xui_bitmap* cocos_resource::icon_left		= NULL;
xui_bitmap* cocos_resource::icon_right		= NULL;
xui_bitmap* cocos_resource::icon_layerview	= NULL;
xui_bitmap* cocos_resource::icon_visible	= NULL;
xui_bitmap* cocos_resource::icon_lead		= NULL;
xui_bitmap* cocos_resource::icon_layer		= NULL;
xui_bitmap* cocos_resource::icon_circle		= NULL;
xui_bitmap* cocos_resource::icon_texture	= NULL;
xui_bitmap* cocos_resource::icon_particle	= NULL;
xui_bitmap* cocos_resource::icon_module		= NULL;
xui_bitmap* cocos_resource::icon_sprite		= NULL;
xui_bitmap* cocos_resource::icon_action		= NULL;
xui_bitmap* cocos_resource::icon_resource	= NULL;
xui_bitmap* cocos_resource::icon_framekey	= NULL;
xui_bitmap* cocos_resource::icon_entity		= NULL;
xui_bitmap* cocos_resource::icon_component	= NULL;
xui_bitmap* cocos_resource::icon_add		= NULL;
xui_bitmap* cocos_resource::icon_remove		= NULL;
xui_bitmap* cocos_resource::icon_copy		= NULL;
xui_bitmap* cocos_resource::icon_paste		= NULL;
xui_bitmap* cocos_resource::icon_cut		= NULL;
xui_bitmap* cocos_resource::icon_setting	= NULL;
xui_bitmap* cocos_resource::icon_horzleft	= NULL;
xui_bitmap* cocos_resource::icon_horzcenter	= NULL;
xui_bitmap* cocos_resource::icon_horzright	= NULL;
xui_bitmap* cocos_resource::icon_verttop	= NULL;
xui_bitmap* cocos_resource::icon_vertcenter	= NULL;
xui_bitmap* cocos_resource::icon_vertbottom	= NULL;
xui_bitmap* cocos_resource::icon_horzinc	= NULL;
xui_bitmap* cocos_resource::icon_horzdec	= NULL;
xui_bitmap* cocos_resource::icon_horzcancel	= NULL;
xui_bitmap* cocos_resource::icon_horzequal	= NULL;
xui_bitmap* cocos_resource::icon_vertinc	= NULL;
xui_bitmap* cocos_resource::icon_vertdec	= NULL;
xui_bitmap* cocos_resource::icon_vertcancel = NULL;
xui_bitmap* cocos_resource::icon_vertequal	= NULL;
xui_bitmap* cocos_resource::icon_cwrotate	= NULL;
xui_bitmap* cocos_resource::icon_ccrotate	= NULL;
xui_bitmap*	cocos_resource::icon_bigpivot	= NULL;
xui_bitmap* cocos_resource::icon_biglarrow	= NULL;
xui_bitmap*	cocos_resource::icon_bigrarrow	= NULL;
xui_bitmap* cocos_resource::icon_bigtarrow	= NULL;
xui_bitmap*	cocos_resource::icon_bigbarrow	= NULL;
xui_bitmap* cocos_resource::icon_magent		= NULL;
xui_bitmap* cocos_resource::icon_build		= NULL;
xui_bitmap* cocos_resource::icon_save		= NULL;
xui_bitmap* cocos_resource::icon_window		= NULL;
xui_bitmap* cocos_resource::icon_legend		= NULL;
xui_bitmap* cocos_resource::icon_design		= NULL;
xui_bitmap* cocos_resource::icon_transform	= NULL;
xui_bitmap* cocos_resource::icon_visual		= NULL;
xui_bitmap* cocos_resource::icon_physics	= NULL;
xui_bitmap* cocos_resource::icon_input		= NULL;
xui_bitmap* cocos_resource::icon_ai			= NULL;
xui_bitmap* cocos_resource::icon_filter		= NULL;
xui_bitmap* cocos_resource::icon_favorite	= NULL;
xui_bitmap* cocos_resource::icon_custom		= NULL;
xui_bitmap* cocos_resource::icon_anchorl	= NULL;
xui_bitmap* cocos_resource::icon_anchorr	= NULL;
xui_bitmap* cocos_resource::icon_anchort	= NULL;
xui_bitmap* cocos_resource::icon_anchorb	= NULL;

xui_method_explain(cocos_resource, init, void)( void )
{
	icon_pickcolour	= xui_bitmap::create("icon/pickcolour.png");
	icon_pickselect = xui_bitmap::create("icon/pickselect.png");
	icon_loop		= xui_bitmap::create("icon/loop.png");
	icon_animator	= xui_bitmap::create("icon/animator.png");
	icon_bigerror	= xui_bitmap::create("icon/bigerror.png");
	icon_bigmessage	= xui_bitmap::create("icon/bigmessage.png");
	icon_bigwarning	= xui_bitmap::create("icon/bigwarning.png");
	icon_center		= xui_bitmap::create("icon/center.png");
	icon_clear		= xui_bitmap::create("icon/clear.png");
	icon_console	= xui_bitmap::create("icon/console.png");
	icon_delete		= xui_bitmap::create("icon/delete.png");
	icon_error		= xui_bitmap::create("icon/error.png");
	icon_file		= xui_bitmap::create("icon/file.png");
	icon_folder		= xui_bitmap::create("icon/folder.png");
	icon_game		= xui_bitmap::create("icon/game.png");
	icon_hierarchy	= xui_bitmap::create("icon/hierarchy.png");
	icon_inspector	= xui_bitmap::create("icon/inspector.png");
	icon_local		= xui_bitmap::create("icon/local.png");
	icon_message	= xui_bitmap::create("icon/message.png");
	icon_pivot		= xui_bitmap::create("icon/pivot.png");
	icon_project	= xui_bitmap::create("icon/project.png");
	icon_rotation	= xui_bitmap::create("icon/rotation.png");
	icon_scale		= xui_bitmap::create("icon/scale.png");
	icon_scene		= xui_bitmap::create("icon/scene.png");
	icon_search		= xui_bitmap::create("icon/search.png");
	icon_select		= xui_bitmap::create("icon/select.png");
	icon_timeline	= xui_bitmap::create("icon/timeline.png");
	icon_translate	= xui_bitmap::create("icon/translate.png");
	icon_warning	= xui_bitmap::create("icon/warning.png");
	icon_world		= xui_bitmap::create("icon/world.png");
	icon_state		= xui_bitmap::create("icon/state.png");
	icon_transition = xui_bitmap::create("icon/transition.png");
	icon_leftright	= xui_bitmap::create("icon/leftright.png");
	icon_topbottom	= xui_bitmap::create("icon/topbottom.png");
	icon_small		= xui_bitmap::create("icon/small.png");
	icon_large		= xui_bitmap::create("icon/large.png");
	icon_reset		= xui_bitmap::create("icon/reset.png");
	icon_play		= xui_bitmap::create("icon/play.png");
	icon_back		= xui_bitmap::create("icon/back.png");
	icon_left		= xui_bitmap::create("icon/left.png");
	icon_right		= xui_bitmap::create("icon/right.png");
	icon_layerview	= xui_bitmap::create("icon/layerview.png");
	icon_visible	= xui_bitmap::create("icon/visible.png");
	icon_lead		= xui_bitmap::create("icon/lead.png");
	icon_layer		= xui_bitmap::create("icon/layer.png");
	icon_circle		= xui_bitmap::create("icon/circle.png");
	icon_texture	= xui_bitmap::create("icon/texture.png");
	icon_particle	= xui_bitmap::create("icon/particle.png");
	icon_module		= xui_bitmap::create("icon/module.png");
	icon_sprite		= xui_bitmap::create("icon/sprite.png");
	icon_action		= xui_bitmap::create("icon/action.png");
	icon_resource	= xui_bitmap::create("icon/resource.png");
	icon_framekey	= xui_bitmap::create("icon/framekey.png");
	icon_entity		= xui_bitmap::create("icon/entity.png");
	icon_component	= xui_bitmap::create("icon/component.png");
	icon_add		= xui_bitmap::create("icon/add.png");
	icon_remove		= xui_bitmap::create("icon/remove.png");
	icon_copy		= xui_bitmap::create("icon/copy.png");
	icon_cut		= xui_bitmap::create("icon/cut.png");
	icon_paste		= xui_bitmap::create("icon/paste.png");
	icon_setting	= xui_bitmap::create("icon/setting.png");
	icon_horzleft	= xui_bitmap::create("icon/horzleft.png");
	icon_horzcenter	= xui_bitmap::create("icon/horzcenter.png");
	icon_horzright	= xui_bitmap::create("icon/horzright.png");
	icon_verttop	= xui_bitmap::create("icon/verttop.png");
	icon_vertcenter	= xui_bitmap::create("icon/vertcenter.png");
	icon_vertbottom	= xui_bitmap::create("icon/vertbottom.png");
	icon_horzinc	= xui_bitmap::create("icon/horzinc.png");
	icon_horzdec	= xui_bitmap::create("icon/horzdec.png");
	icon_horzcancel	= xui_bitmap::create("icon/horzcancel.png");
	icon_horzequal	= xui_bitmap::create("icon/horzequal.png");
	icon_vertinc	= xui_bitmap::create("icon/vertinc.png");
	icon_vertdec	= xui_bitmap::create("icon/vertdec.png");
	icon_vertcancel	= xui_bitmap::create("icon/vertcancel.png");
	icon_vertequal	= xui_bitmap::create("icon/vertequal.png");
	icon_cwrotate	= xui_bitmap::create("icon/cwrotate.png");
	icon_ccrotate	= xui_bitmap::create("icon/ccrotate.png");
	icon_bigpivot	= xui_bitmap::create("icon/bigpivot.png");
	icon_biglarrow	= xui_bitmap::create("icon/biglarrow.png");
	icon_bigrarrow	= xui_bitmap::create("icon/bigrarrow.png");
	icon_bigtarrow	= xui_bitmap::create("icon/bigtarrow.png");
	icon_bigbarrow	= xui_bitmap::create("icon/bigbarrow.png");
	icon_magent		= xui_bitmap::create("icon/magent.png");
	icon_build		= xui_bitmap::create("icon/build.png");
	icon_save		= xui_bitmap::create("icon/save.png");
	icon_window		= xui_bitmap::create("icon/window.png");
	icon_legend		= xui_bitmap::create("icon/legend.png");
	icon_design		= xui_bitmap::create("icon/design.png");
	icon_transform	= xui_bitmap::create("icon/transform.png");
	icon_visual		= xui_bitmap::create("icon/visual.png");
	icon_physics	= xui_bitmap::create("icon/physics.png");
	icon_input		= xui_bitmap::create("icon/input.png");
	icon_ai			= xui_bitmap::create("icon/ai.png");
	icon_filter		= xui_bitmap::create("icon/filter.png");
	icon_favorite	= xui_bitmap::create("icon/favorite.png");
	icon_custom		= xui_bitmap::create("icon/custom.png");
	icon_anchorl	= xui_bitmap::create("icon/anchorl.png");
	icon_anchorr	= xui_bitmap::create("icon/anchorr.png");
	icon_anchort	= xui_bitmap::create("icon/anchort.png");
	icon_anchorb	= xui_bitmap::create("icon/anchorb.png");

	xui_global::add_cursor(CURSOR_DRAG,		L"icon/arrowdrag.cur");
	xui_global::add_cursor(CURSOR_FORBID,	L"icon/forbid.cur");
	xui_global::icon_pickcolour = icon_pickcolour;
	xui_global::icon_pickselect = icon_pickselect;
	xui_global::icon_loop		= icon_loop;
}