#include "d/actor/d_grass.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_player.h"
#include "d/d_s_play.h"
#include "JSystem/J3DGraphBase/J3DDrawBuffer.h"
#include "SSystem/SComponent/c_lib.h"
#include "f_op/f_op_overlap_mng.h"
#include <gf.h>
#include <cstring>

#include "d/d_camera.h"
#include "f_op/f_op_camera_mng.h"

const u16 l_M_Hijiki00TEX__width = 31;
const u16 l_M_Hijiki00TEX__height = 31;
#include "assets/l_M_kusa05_RGBATEX.h"  // ALIGN 32

const u16 l_M_kusa05_RGBATEX__width = 31;
const u16 l_M_kusa05_RGBATEX__height = 31;
#include "assets/l_M_Hijiki00TEX.h"  // ALIGN 32

static Vec l_pos[80] = {
    {0.7903890013694763f, -40.0f, 31.38666534423828f},
    {21.341754913330078f, -40.0f, -22.876697540283203f},
    {53.388118743896484f, 147.08689880371094f, -6.223147869110107f},
    {28.471284866333008f, 147.08689880371094f, 46.61578369140625f},
    {-27.870378494262695f, -40.0f, -12.937013626098633f},
    {-42.033714294433594f, 147.08689880371094f, -33.85758972167969f},
    {13.082502365112305f, 147.08689880371094f, -53.222633361816406f},
    {-17.230276107788086f, 147.08689880371094f, 49.84426498413086f},
    {-54.27837371826172f, 147.08689880371094f, 4.6751790046691895f},
    {0.7284020185470581f, 147.08689880371094f, 28.106000900268555f},
    {-28.388214111328125f, 147.08689880371094f, 54.716094970703125f},
    {-29.77798843383789f, -40.0f, 24.548357009887695f},
    {0.0f, -40.0f, 0.0f},
    {32.83451461791992f, -40.0f, 8.5589017868042f},
    {37.18562698364258f, 147.08689880371094f, 47.58406448364258f},
    {19.315916061401367f, 147.08689880371094f, -20.9720516204834f},
    {58.707496643066406f, 147.08689880371094f, -18.92852210998535f},
    {-9.612780570983887f, -40.0f, -37.49454879760742f},
    {7.582291126251221f, 147.08689880371094f, -60.605953216552734f},
    {-25.19359016418457f, 147.08689880371094f, -11.98218822479248f},
    {-36.74598693847656f, 147.08689880371094f, -49.69718551635742f},
    {-58.424095153808594f, 147.08689880371094f, 12.59939193725586f},
    {0.36420100927352905f, 35.60452651977539f, 14.053000450134277f},
    {-29.083101272583008f, 35.60452651977539f, 39.632225036621094f},
    {-29.77798843383789f, -20.0f, 24.548357009887695f},
    {0.0f, -20.0f, 0.0f},
    {32.83451461791992f, -20.0f, 8.5589017868042f},
    {35.01007080078125f, 35.60452651977539f, 28.07148551940918f},
    {9.657958030700684f, 35.60452651977539f, -10.4860258102417f},
    {45.7710075378418f, 35.60452651977539f, -5.184810161590576f},
    {-9.612780570983887f, -20.0f, -37.49454879760742f},
    {-1.015244960784912f, 35.60452651977539f, -49.050254821777344f},
    {-12.596796035766602f, 35.60452651977539f, -5.99109411239624f},
    {-23.17938232421875f, 35.60452651977539f, -43.59586715698242f},
    {-44.101043701171875f, 35.60452651977539f, 18.57387351989746f},
    {0.7903890013694763f, -20.0f, 31.38666534423828f},
    {21.341754913330078f, -20.0f, -22.876697540283203f},
    {37.36493682861328f, 26.62445068359375f, -14.549922943115234f},
    {14.63083553314209f, 26.62445068359375f, 39.001224517822266f},
    {-27.870378494262695f, -20.0f, -12.937013626098633f},
    {-34.95204544067383f, 26.62445068359375f, -23.397302627563477f},
    {17.212129592895508f, 26.62445068359375f, -38.04966354370117f},
    {-8.21994400024414f, 26.62445068359375f, 40.61546325683594f},
    {-41.07437515258789f, 26.62445068359375f, -4.130918025970459f},
    {12.466093063354492f, 318.9329833984375f, 112.12455749511719f},
    {17.30784034729004f, -33.29464340209961f, -25.982749938964844f},
    {-17.52573013305664f, -46.70535659790039f, 5.062126159667969f},
    {135.3618927001953f, 183.44113159179688f, 64.27802276611328f},
    {5.482818126678467f, 3.437272071838379f, 20.346359252929688f},
    {-0.28113600611686707f, 26.854970932006836f, -7.9895548820495605f},
    {49.88279342651367f, 241.34536743164062f, -58.620243072509766f},
    {15.589160919189453f, 63.269920349121094f, 24.69953727722168f},
    {-11.820823669433594f, 74.0556640625f, 30.859477996826172f},
    {111.84452056884766f, 325.5053405761719f, -10.264846801757812f},
    {-26.26278305053711f, -26.722274780273438f, -15.106595039367676f},
    {4.782092094421387f, -40.13298416137695f, 19.72697639465332f},
    {23.391246795654297f, 185.65516662597656f, -145.55126953125f},
    {17.73554229736328f, 5.651328086853027f, -6.90873908996582f},
    {-8.143026351928711f, 29.069026947021484f, 5.992685794830322f},
    {-27.13127899169922f, 232.35208129882812f, -51.97594451904297f},
    {16.285825729370117f, 54.525108337402344f, -17.219552993774414f},
    {22.445764541625977f, 65.31085205078125f, 10.190431594848633f},
    {-17.639142990112305f, 318.9329833984375f, -114.93612670898438f},
    {-22.48089027404785f, -33.29464340209961f, 23.17118263244629f},
    {12.352680206298828f, -46.70535659790039f, -7.873693943023682f},
    {-150.09400939941406f, 185.65516662597656f, -33.859073638916016f},
    {-15.072240829467773f, 5.651328086853027f, -21.808794021606445f},
    {-2.1708168983459473f, 29.069026947021484f, 4.069775104522705f},
    {-44.89584732055664f, 223.45846557617188f, 0.11934299767017365f},
    {-19.853805541992188f, 63.269920349121094f, -27.728796005249023f},
    {7.556179046630859f, 74.0556640625f, -33.888736724853516f},
    {-112.46688842773438f, 320.14666748046875f, -18.225887298583984f},
    {19.681379318237305f, -32.0809211730957f, 22.195709228515625f},
    {-1.2900700569152832f, -45.49163818359375f, -19.485946655273438f},
    {-66.35687255859375f, 195.04721069335938f, 125.25151824951172f},
    {-25.5610294342041f, 15.66256332397461f, 2.2459840774536133f},
    {2.774880886077881f, 39.08026123046875f, -3.517957925796509f},
    {48.434696197509766f, 242.55909729003906f, 40.98846435546875f},
    {-28.73975944519043f, 64.48363494873047f, 6.767571926116943f},
    {-27.595571517944336f, 75.26937866210938f, -21.302751541137695f},
};

static Vec l_normal = {0.0f, 1.0f, 0.0f};

static GXColor l_color[5] = {
    {0xFF, 0xFF, 0xFF, 0x00}, {0xFF, 0xFF, 0xFF, 0x80}, {0xFF, 0xFF, 0xFF, 0x79},
    {0xFF, 0xFF, 0xFF, 0x73}, {0xFF, 0xFF, 0xFF, 0xFF},
};

static f32 l_texCoord[20][2] = {
    {1.0543869733810425f, 1.21875f},
    {2.054387092590332f, 1.21875f},
    {2.054387092590332f, 0.03125f},
    {1.0543869733810425f, 0.03125f},
    {0.0f, 0.03125f},
    {-1.0f, 0.03125f},
    {-1.0f, 1.21875f},
    {0.0f, 1.21875f},
    {1.0f, 0.03125f},
    {1.0f, 1.21875f},
    {0.0f, 0.384672},
    {-1.0f, 0.38467198610305786f},
    {1.0f, 0.38467198610305786f},
    {2.054387092590332f, 0.38467198610305786f},
    {1.0543869733810425f, 0.38467198610305786f},
    {0.46875f, -1.71875f},
    {1.15625f, 1.21875f},
    {-0.09375f, 1.21875f},
    {1.15625f, 1.0f},
    {-0.09375f, 1.0f},
};

#include "assets/l_M_Kusa_9qDL.h"

#include "assets/l_M_Kusa_9q_cDL.h"

#include "assets/l_M_TenGusaDL.h"

#include "assets/l_Tengusa_matDL.h"

l_Tengusa_matDL(l_M_Hijiki00TEX)

#include "assets/l_kusa9q_matDL.h"
l_kusa9q_matDL(l_M_kusa05_RGBATEX)

#include "assets/l_kusa9q_l4_matDL.h"
l_kusa9q_l4_matDL(l_M_kusa05_RGBATEX)

void dGrass_data_c::WorkCo(fopAc_ac_c* i_hitActor, u32 i_massFlg, int i_roomNo) {
    cXyz sp18;

    if (!(dKyw_get_wind_pow() >= 0.6f)) {
        sp18.x = m_pos.x - i_hitActor->current.pos.x;
        sp18.z = m_pos.z - i_hitActor->current.pos.z;

        f32 var_f31 = sp18.abs2XZ();
        if (!(var_f31 > 1600.0f)) {
            sp18.y = m_pos.y - i_hitActor->current.pos.y;

            s16 temp_r26 = cM_atan2s(sp18.x, sp18.z);
            var_f31 = JMAFastSqrt(var_f31);

            dGrass_anm_c* var_r28;
            if (field_0x02 < 16) {
                if (i_hitActor->speedF > 16.0f) {
                    cXyz spC(m_pos.x, 20.0f + m_pos.y, m_pos.z);
                    dKy_tevstr_c* var_r25 = dComIfGp_roomControl_getTevStr(i_roomNo);
                }

                int var_r27 = daGrass_c::getGrass()->newAnm();
                if (var_r27 < 0) {
                    return;
                }

                field_0x02 = var_r27;
                var_r28 = daGrass_c::getGrass()->getAnm(field_0x02);
            } else {
                var_r28 = daGrass_c::getGrass()->getAnm(field_0x02);
            }

            cLib_addCalcAngleS(&var_r28->m_angY, temp_r26, 20, 4000, 1);
            cLib_addCalcAngleS(&var_r28->m_angX, cM_atan2s(40.0f - var_f31, 65.0f), 10, 4000, 1);
            var_r28->m_state = 2;
        }
    }
}

void dGrass_data_c::WorkAt_NoCutAnim(fopAc_ac_c* i_hitActor, u32 i_massFlg, int i_roomNo, dCcMassS_HitInf* i_hitinf, cCcD_Obj* i_hitObj) {
    cXyz spC;
    dCcD_GObjInf* gobj_p = dCcD_GetGObjInf(i_hitObj);

    f32 var_f31;
    s16 var_r26;
    if (i_hitObj == NULL) {
        spC.x = m_pos.x - i_hitActor->current.pos.x;
        spC.y = m_pos.y - i_hitActor->current.pos.y;
        spC.z = m_pos.z - i_hitActor->current.pos.z;

        var_f31 = spC.abs2XZ();
        var_r26 = i_hitActor->shape_angle.y;
    } else {
        spC = *dCcD_GetGObjInf(i_hitObj)->GetAtVecP();
        var_f31 = spC.abs2XZ();

        if (cM3d_IsZero(var_f31)) {
            cCcD_ShapeAttr* shape = i_hitObj->GetShapeAttr();
            if (shape->GetNVec(m_pos, &spC)) {
                PSVECScale(&spC, &spC, 5.0f);
                var_f31 = spC.abs2XZ();
            } else {
                spC.x = m_pos.x - i_hitActor->current.pos.x;
                spC.y = m_pos.y - i_hitActor->current.pos.y;
                spC.z = m_pos.z - i_hitActor->current.pos.z;

                var_f31 = spC.abs2XZ();
            }
        }

        if (cM3d_IsZero(var_f31)) {
            return;
        }

        var_r26 = cM_atan2s(spC.x, spC.z);
    }

    dGrass_anm_c* anm_p;
    if (field_0x02 < 16) {
        int var_r25 = daGrass_c::getGrass()->newAnm();
        if (var_r25 < 0) {
            return;
        }

        field_0x02 = var_r25;
        anm_p = daGrass_c::getGrass()->getAnm(field_0x02);
    } else {
        anm_p = daGrass_c::getGrass()->getAnm(field_0x02);
    }

    anm_p->m_angY = var_r26 * (0.9f + (0.2f * cM_rnd()));

    if (i_hitObj->ChkAtType(AT_TYPE_BOMB)) {
        anm_p->m_angX = cM_atan2s(var_f31, 40.0f) * (2.5f + (0.5f * cM_rnd()));
    } else if (i_hitObj->ChkAtType(AT_TYPE_BOOMERANG)) {
        anm_p->m_angX = cM_atan2s(var_f31, 40.0f) * (1.5f + (0.5f * cM_rnd()));
    } else if (i_hitObj->ChkAtType(AT_TYPE_100) || i_hitObj->ChkAtType(AT_TYPE_LANTERN_SWING)) {
        anm_p->m_angX = 0.05f * (cM_atan2s(var_f31, 40.0f) * (1.5f + cM_rnd()));
    } else if (daPy_getPlayerActorClass()->getCutType() >= daPy_py_c::CUT_TYPE_NM_VERTICAL && daPy_getPlayerActorClass()->getCutType() <= daPy_py_c::CUT_TYPE_FINISH_VERTICAL) {
        anm_p->m_angX = 0.5f * (cM_atan2s(var_f31, 20.0f) * (0.5f + (0.2f * cM_rnd())));
    } else if (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_RIGHT ||
               daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_LEFT ||
               daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_RIGHT ||
               daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_LEFT)
    {
        anm_p->m_angX = cM_atan2s(var_f31, 40.0f) * (1.5f + (0.3f * cM_rnd()));
    } else {
        anm_p->m_angX = cM_atan2s(var_f31, 40.0f) * (0.9f + (0.2f * cM_rnd()));
    }

    anm_p->m_state = 2;
}

void dGrass_data_c::Direction_Set(fopAc_ac_c* i_hitActor, u32 i_massFlg, int i_roomNo,
                                  dCcMassS_HitInf* i_hitinf, cCcD_Obj* i_hitObj, csXyz* i_rotation) {
    cXyz sp8;

    f32 var_f31;
    s16 var_r27;
    if (i_hitObj == NULL) {
        sp8.x = m_pos.x - i_hitActor->current.pos.x;
        sp8.y = m_pos.y - i_hitActor->current.pos.y;
        sp8.z = m_pos.z - i_hitActor->current.pos.z;

        var_f31 = sp8.abs2XZ();
        var_r27 = i_hitActor->shape_angle.y;
    } else {
        sp8 = *dCcD_GetGObjInf(i_hitObj)->GetAtVecP();
        var_f31 = sp8.abs2XZ();

        if (cM3d_IsZero(var_f31)) {
            cCcD_ShapeAttr* shape = i_hitObj->GetShapeAttr();
            if (shape->GetNVec(m_pos, &sp8)) {
                PSVECScale(&sp8, &sp8, 5.0f);
                var_f31 = sp8.abs2XZ();
            } else {
                sp8.x = m_pos.x - i_hitActor->current.pos.x;
                sp8.y = m_pos.y - i_hitActor->current.pos.y;
                sp8.z = m_pos.z - i_hitActor->current.pos.z;

                var_f31 = sp8.abs2XZ();
            }
        }

        if (cM3d_IsZero(var_f31)) {
            return;
        }

        var_r27 = cM_atan2s(sp8.x, sp8.z);
    }

    i_rotation->y = var_r27 * (0.89999998f + (0.2f * cM_rnd()));
    i_rotation->x = 0.6f * (cM_atan2s(var_f31, 40.0f));
    i_rotation->z = 0;
}

static u8 data_8052790d;

void dGrass_data_c::WorkAt(fopAc_ac_c* i_hitActor, u32 i_massFlg, int i_roomNo, dCcMassS_HitInf* i_hitinf,
                           u16 i_particleID) {
    cCcD_Obj* hit_obj = i_hitinf->GetAtHitObj();

    if (hit_obj != NULL) {
        if (hit_obj->ChkAtType(0) || hit_obj->ChkAtType(AT_TYPE_ARROW) ||
            hit_obj->ChkAtType(AT_TYPE_SLINGSHOT) || hit_obj->ChkAtType(AT_TYPE_20000000) ||
            hit_obj->ChkAtType(AT_TYPE_SHIELD_ATTACK) || hit_obj->ChkAtType(AT_TYPE_BOOMERANG) ||
            hit_obj->ChkAtType(AT_TYPE_100) || hit_obj->ChkAtType(AT_TYPE_LANTERN_SWING) ||
            hit_obj->ChkAtType(AT_TYPE_HOOKSHOT))
        {
            WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hit_obj);
            return;
        }
    }

    fopAc_ac_c* player_p = dComIfGp_getPlayer(0);
    if (hit_obj->ChkAtType(AT_TYPE_BOMB)) {
        if (i_hitActor != NULL && m_pos.abs(i_hitActor->current.pos) > 200.0f) {
            WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hit_obj);
            return;
        }
    } else if (daPy_getPlayerActorClass()->getCutType() >= daPy_py_c::CUT_TYPE_NM_RIGHT &&
               daPy_getPlayerActorClass()->getCutType() <= daPy_py_c::CUT_TYPE_FINISH_VERTICAL)
    {
        if (m_pos.abs(player_p->current.pos) > 158.0f) {
            if (m_pos.abs(player_p->current.pos) < 200.0f) {
                WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hit_obj);
            }
            return;
        }
    } else if (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_RIGHT ||
               daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_LEFT)
    {
        if (m_pos.abs(player_p->current.pos) > 200.0f) {
            WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hit_obj);
            return;
        }
    } else if (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_RIGHT ||
               daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_LEFT)
    {
        if (m_pos.abs(player_p->current.pos) > 500.0f) {
            WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hit_obj);
            return;
        }
    } else if (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_NM_VERTICAL ||
               daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_NM_STAB)
    {
        if (m_pos.abs(player_p->current.pos) > 158.0f) {
            return;
        }
    }

    if (field_0x02 >= 16) {
        daGrass_c::getGrass()->deleteAnm(field_0x02);
    }

    int itemBitNo = m_itemBitNo;
    if (m_itemBitNo == 0xFF) {
        itemBitNo = -1;
    }

    bool create_direct = false;
    if (daPy_getPlayerActorClass()->checkHorseRide()) {
        create_direct = true;
    }

    fopAcM_createItemFromTable(&m_pos, m_tableNo, itemBitNo, i_roomNo, NULL, 0, NULL, NULL, NULL,
                               create_direct);

    field_0x02 = -1;

    static csXyz ang(0, 0, 0);

    cXyz particle_pos(m_pos.x, m_pos.y + 25.0f, m_pos.z);
    dKy_tevstr_c* tevstr = dComIfGp_roomControl_getTevStr(i_roomNo);

    csXyz particle_rot;
    Direction_Set(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hit_obj, &particle_rot);

    GXColor envcolor;
    envcolor.r = m_addCol >> 8;
    envcolor.g = m_addCol & 0xFF;
    dComIfGp_particle_set(i_particleID, &particle_pos, tevstr, &particle_rot, NULL, 255,
                          dPa_control_c::getLight8EcallBack(), -1, &envcolor, NULL, NULL);

    if (data_8052790d == 0) {
        data_8052790d = 1;
        mDoAud_seStart(JA_SE_LK_CUT_GRASS, &m_pos, 0, dComIfGp_getReverb(i_roomNo));
    }
}

void dGrass_data_c::hitCheck(int i_roomNo, u16 i_particleName) {
    dCcMassS_HitInf hitinf;
    fopAc_ac_c* hit_actor;

    u32 mass_flags = dComIfG_Ccsp()->ChkMass(&m_pos, &hit_actor, &hitinf);
    bool at_hit = (mass_flags & 1) && (hit_actor != NULL && fopAcM_GetName(hit_actor) != fpcNm_Obj_Carry_e);

    if (!(mass_flags & 2) && !at_hit) {
        if (field_0x02 >= 16) {
            dGrass_anm_c* anm_p = daGrass_c::getGrass()->getAnm(field_0x02);
            s16 spC = anm_p->m_angY & 0xE000;
            int sp10 = (field_0x02 & 15) & 0xFFFF;
            dGrass_anm_c* temp_r27 = daGrass_c::getGrass()->getAnm(sp10);

            if (anm_p->m_state == 2) {
                mDoAud_seStart(JA_SE_FT_ADD_GRASS, &m_pos, 0, dComIfGp_getReverb(i_roomNo));
                anm_p->m_state = 1;
            }

            if (cLib_addCalcAngleS(&anm_p->m_angX, temp_r27->m_angX, 10, 4400, 400) == 0) {
                if (cLib_addCalcAngleS(&anm_p->m_angY, temp_r27->m_angY, 10, 4400, 400) == 0) {
                    daGrass_c::getGrass()->deleteAnm(field_0x02);
                    field_0x02 &= 15;
                }
            }
        }
    } else {
        if (mass_flags & 2) {
            WorkCo(hit_actor, mass_flags, i_roomNo);
        }

        if (at_hit) {
            WorkAt(hit_actor, mass_flags, i_roomNo, &hitinf, i_particleName);
        }
    }
}

void dGrass_room_c::newData(dGrass_data_c* i_data) {
    i_data->mp_next = mp_data;
    mp_data = i_data;
}

void dGrass_room_c::deleteData() {
    while (mp_data != NULL) {
        mp_data->m_state = 0;

        s8 anm_id = mp_data->field_0x02;
        if (anm_id >= 16) {
            daGrass_c::getGrass()->deleteAnm(anm_id);
            mp_data->field_0x02 = cM_rnd() * 15.0f;
        }

        mp_data = mp_data->mp_next;
    }
}

dGrass_packet_c::dGrass_packet_c() {
    dGrass_data_c* data_p = m_data;
    for (int i = 0; i < 1500; i++) {
        data_p->m_state = 0;
        data_p++;
    }

    m_dataNum = 0;

    dGrass_anm_c* anm_p = m_anm;
    for (int i = 0; i < 112; i++) {
        anm_p->m_state = 0;
        anm_p++;
    }

    s16 unused = 0;
    for (int i = 0; i < 16; i++) {
        setAnm(i, unused);
        unused += 0x1000;
    }

    mp_pos = l_pos;
    mp_normal = &l_normal;
    mp_colors = l_color;
    mp_texCoords = &l_texCoord[0][0];
    mp_kusa9q_DL = l_kusa9q_matDL;
    m_kusa9q_DL_size = 0xA0;
    mp_kusa9q_14_DL = l_kusa9q_l4_matDL;
    m_kusa9q_DL_14_size = 0xA0;
    mp_Mkusa_9q_DL = l_M_Kusa_9qDL;
    m_Mkusa_9q_DL_size = 0xC0;
    mp_Mkusa_9q_cDL = l_M_Kusa_9q_cDL;
    m_Mkusa_9q_cDL_size = 0xC0;
    field_0x1d714 = 0;

    OS_REPORT("草群メモリ=%fＫ\n", sizeof(*this) / 1024.f);
    
    m_deleteRoom = &dGrass_packet_c::deleteRoom;
}

void dGrass_packet_c::draw() {
    dScnKy_env_light_c* kankyo = dKy_getEnvlight();
    cXyz spB4;
    cXyz spA8;

    j3dSys.reinitGX();
    GXSetNumIndStages(0);
    dKy_setLight_again();
    GXClearVtxDesc();

    static GXVtxDescList l_vtxDescList[] = {
        {GX_VA_POS, GX_INDEX8},
        {GX_VA_NRM, GX_INDEX8},
        {GX_VA_CLR0, GX_INDEX8},
        {GX_VA_TEX0, GX_INDEX8},
        {GX_VA_NULL, GX_NONE},
    };

    static GXVtxAttrFmtList l_vtxAttrFmtList[] = {
        GX_VA_POS,
        GX_POS_XYZ,
        GX_F32,
        0,

        GX_VA_NRM,
        GX_NRM_XYZ,
        GX_F32,
        0,

        GX_VA_CLR0,
        GX_CLR_RGBA,
        GX_RGBA8,
        0,

        GX_VA_TEX0,
        GX_TEX_ST,
        GX_F32,
        0,

        GX_VA_NULL,
        GX_TEX_ST,
        GX_S8,
        0,
    };

    GXSetVtxDescv(l_vtxDescList);
    GXSetVtxAttrFmtv(GX_VTXFMT0, l_vtxAttrFmtList);
    GXSetArray(GX_VA_POS, mp_pos, sizeof(Vec));
    GXSetArray(GX_VA_NRM, mp_normal, sizeof(Vec));
    GXSetArray(GX_VA_CLR0, mp_colors, sizeof(GXColor));
    GXSetArray(GX_VA_TEX0, mp_texCoords, sizeof(f32[2]));

    GXColorS10 spA0 = {0, 0, 0, 0};
    GXColorS10 sp98 = {0, 0, 0, 0};

    dGrass_room_c* sp54 = m_room;

    f32 var_f31 = g_env_light.getDaytime();
    f32 var_f30;
    f32 var_f29;
    if (var_f31 >= 90.0f && var_f31 < 135.0f) {
        var_f30 = 1.0f - (0.022222223f * (135.0f - var_f31));
        var_f29 = 100.0f - (18.0f * var_f30);
    } else if (var_f31 >= 135.0f && var_f31 < 225.0f) {
        var_f30 = 1.0f - (0.011111111f * (225.0f - var_f31));
        var_f29 = 82.0f - (25.0f * var_f30);
    } else if (var_f31 >= 225.0f && var_f31 < 270.0f) {
        var_f30 = 1.0f - (0.022222223f * (270.0f - var_f31));
        var_f29 = 57.0f - (-25.0f * var_f30);
    } else if (var_f31 >= 270.0f && var_f31 < 315.0f) {
        var_f30 = (1.0f - (0.022222223f * (315.0f - var_f31)));
        var_f29 = 82.0f - (-18.0f * var_f30);
    } else {
        var_f29 = 100.0f;
    }

#if DEBUG
    if (g_kankyoHIO.navy.grass_shine_value != 0.0f) {
        var_f29 = g_kankyoHIO.navy.grass_shine_value;
    }
#endif

    for (int i = 0; i < 64; i++) {
        dGrass_data_c* var_r29 = sp54->getData();
        if (var_r29 != NULL && dComIfGp_roomControl_checkStatusFlag(i, 0x10)) {
            int sp4C = 0;
            int sp48 = 6;
            dKy_tevstr_c* sp44 = dComIfGp_roomControl_getTevStr(i);

            f32 temp_f27 = g_env_light.grass_light_inf_rate * g_env_light.bg_light_influence;
            f32 sp58 = 1.0f - temp_f27;
            temp_f27 += 0.5f * sp58;

            J3DLightInfo* sp40 = sp44->mLights[0].getLightInfo();
            sp98.r = sp40->mColor.r * temp_f27;
            sp98.g = sp40->mColor.g * temp_f27;
            sp98.b = sp40->mColor.b * temp_f27;
            sp98.a = var_f29;

            if (memcmp(dComIfGp_getStartStageName(), "D_MN01", 6) == 0) {
                sp98.r = 0;
                sp98.g = 0x1E;
                sp98.b = 5;
                sp98.a = 0x50;
            }

            GFSetTevColorS10(GX_TEVREG1, sp98);

            if (dComIfGp_roomControl_getStatusRoomDt(i) != NULL) {
                sp48 = dComIfGp_roomControl_getStatusRoomDt(i)->getLightVecInfoNum();
            }

#if DEBUG
            if (g_kankyoHIO.light.m_HOSTIO_setting != 0) {
                sp48 = g_kankyoHIO.dungeonLight.usedLights;
            }
#endif

            if (dKy_SunMoon_Light_Check() == TRUE && sp48 < 2) {
                sp48 = 2;
            }

            for (int j = 0; j < 6; j++) {
                if (kankyo->field_0x0c18[j].field_0x26 == 1) {
                    sp48++;
                }
            }

            if (var_r29->field_0x05 <= 3 || var_r29->field_0x05 >= 10) {
                if (sp48 <= 3) {
                    GXCallDisplayList(mp_kusa9q_14_DL, m_kusa9q_DL_14_size);
                } else {
                    GXCallDisplayList(mp_kusa9q_DL, m_kusa9q_DL_size);
                }
            } else {
                GXCallDisplayList(l_Tengusa_matDL, 0xA0);
            }

            GFSetTevColorS10(GX_TEVREG2, spA0);

            dKy_Global_amb_set(sp44);
            dKy_GfFog_tevstr_set(sp44);
            dKy_setLight_nowroom_grass(sp44->room_no, 0.0f);

            f32 temp1 = 0.001953125f; // fakematch

#if DEBUG
            camera_process_class* sp34 = dComIfGp_getCamera(0);
            int sp30 = 0;
            if (dCam_getBody() != NULL &&
                (dCam_getBody()->Mode() == 7 || dCam_getBody()->Mode() == 8) &&
                sp34 != NULL &&
                dCam_getBody()->V() < -750.0f &&
                var_r29->m_pos.abs(sp34->view.lookat.eye) < 200.0f) {
                sp30 = 1;
            }
#endif

            while (var_r29 != NULL) {
                if (var_r29->field_0x05 <= 3 || var_r29->field_0x05 >= 10) {
                    if (sp48 <= 2) {
                        GXCallDisplayList(mp_kusa9q_14_DL, m_kusa9q_DL_14_size);
                    } else {
                        GXCallDisplayList(mp_kusa9q_DL, m_kusa9q_DL_size);
                    }
                } else {
                    GXCallDisplayList(l_Tengusa_matDL, 0xA0);
                }

                if (var_r29->field_0x02 <= -1) {
                    sp98.a = 0;
                } else {
                    sp98.a = var_f29;
                }

                GFSetTevColorS10(GX_TEVREG1, sp98);

                GXColor sp38;

                if (DEBUG && g_kankyoHIO.navy.grass_adjust_ON) {
                    sp38.r = g_kankyoHIO.navy.grass_ambcol.r * 2;
                    sp38.g = g_kankyoHIO.navy.grass_ambcol.g * 2;
                    sp38.b = g_kankyoHIO.navy.grass_ambcol.b * 2;
                } else {
                    sp38.r = (var_r29->m_addCol & 0x1F) * 2;
                    sp38.g = ((var_r29->m_addCol >> 5) & 0x1F) * 2;
                    sp38.b = ((var_r29->m_addCol >> 0xA) & 0x1F) * 2;

                    if (daPy_py_c::checkNowWolfPowerUp()) {
                        f32 var_f26 = g_env_light.bg_amb_col[0].r / 255.0f;
                        f32 var_f1 = (((var_r29->m_addCol & 0x1F) * 2 + 0x10));
                        sp38.r = var_f1 * (var_f26 * 4.0f);

                        var_f26 = g_env_light.bg_amb_col[0].g / 255.0f;
                        f32 var_f1_2 = (((var_r29->m_addCol >> 5) & 0x1F) * 2 + 0x10);
                        sp38.g = var_f1_2 * (4.0f * var_f26);

                        var_f26 = g_env_light.bg_amb_col[0].b / 255.0f;
                        f32 var_f1_3 = (((var_r29->m_addCol >> 10) & 0x1F) * 2 + 0x10);
                        sp38.b = var_f1_3 * (4.0f * var_f26);
                    }

                    f32 sp2C = 1.0f - (((int)var_r29->m_pos.x & 0xFF) * temp1);

                    f32 var_f28 = 1.1f - (((u8)(int)var_r29->m_pos.x & 0xFF) / 2000.0f);
                    var_f28 -= ((int)var_r29->m_pos.z & 0xFF) / 2000.0f;

                    if (var_f28 > 1.0f) {
                        var_f28 = 1.0f;
                    }

                    if (sp38.r == 0x3E) {
                        sp38.r = sp44->AmbCol.r * sp2C;
                    } else {
                        sp38.r = sp38.r * var_f28;
                    }

                    if (sp38.g == 0x3E) {
                        sp38.g = sp44->AmbCol.g * sp2C;
                    } else {
                        sp38.g = sp38.g * var_f28;
                    }

                    if (sp38.b == 0x3E) {
                        sp38.b = sp44->AmbCol.b * sp2C;
                    } else {
                        sp38.b = sp38.b * var_f28;
                    }
                }

                GXSetChanAmbColor(GX_COLOR0A0, sp38);

                if (!cLib_checkBit<u8>(var_r29->field_0x01, 2)) {
                    GXLoadPosMtxImm(var_r29->m_modelMtx, 0);
                    GXLoadNrmMtxImm(j3dSys.getViewMtx(), 0);
                    if (var_r29->field_0x05 <= 3 || var_r29->field_0x05 >= 10) {
                        if (var_r29->field_0x02 < -1) {
                            spA0.a = (-0x100 - ((var_r29->field_0x02 << 8) / 40));
                            GFSetTevColorS10(GX_TEVREG2, spA0);

                            if (var_r29->field_0x02 != -2) {
                                GXCallDisplayList(mp_Mkusa_9q_DL, m_Mkusa_9q_DL_size);
                            } else {
                                GXCallDisplayList(mp_Mkusa_9q_cDL, m_Mkusa_9q_cDL_size);
                            }

                            spA0.a = 0;
                            GFSetTevColorS10(GX_TEVREG2, spA0);
                        } else if (var_r29->field_0x02 >= 0) {
                            GXCallDisplayList(mp_Mkusa_9q_DL, m_Mkusa_9q_DL_size);
                        } else {
                            GXCallDisplayList(mp_Mkusa_9q_cDL, m_Mkusa_9q_cDL_size);
                        }
                    } else if (var_r29->field_0x02 < -1) {
                        spA0.a = (-0x100 - ((var_r29->field_0x02 << 8) / 40));
                        GFSetTevColorS10(GX_TEVREG2, spA0);

                        if (var_r29->field_0x02 != -2) {
                            GXCallDisplayList(l_M_TenGusaDL, 0xC0);
                        } else {
                            GXCallDisplayList(mp_Mkusa_9q_cDL, m_Mkusa_9q_cDL_size);
                        }
 
                        spA0.a = 0;
                        GFSetTevColorS10(GX_TEVREG2, spA0);
                    } else if (var_r29->field_0x02 >= 0) {
                        GXCallDisplayList(l_M_TenGusaDL, 0xC0);
                    } else {
                        GXCallDisplayList(mp_Mkusa_9q_cDL, m_Mkusa_9q_cDL_size);
                    }
                }

                var_r29 = var_r29->mp_next;
            }
        }
        sp54++;
    }

    J3DShape::resetVcdVatCache();
}

void dGrass_packet_c::calc() {
    cXyz* temp_r29 = dKyw_get_wind_vec();
    f32 var_f31 = dKyw_get_wind_pow() * dKyw_get_wind_pow();

    static s16 exec_count_dammy = 0;
    static s16 exec_count_dammy2 = 0;

    if (var_f31 < 0.09f) {
        var_f31 = 0.09f;
    }

    if (memcmp(dComIfGp_getStartStageName(), "D_MN01", 6) == 0 && temp_r29 != NULL) {
        temp_r29->x = 0.0f;
        temp_r29->y = 0.0f;
        temp_r29->z = 0.0f;
        var_f31 = 0.0f;
    }

    if (memcmp(dComIfGp_getStartStageName(), "D_MN54", 6) == 0 && temp_r29 != NULL) {
        temp_r29->x = 0.0f;
        temp_r29->y = 0.0f;
        temp_r29->z = 0.0f;
        var_f31 = 0.01f;
    }

    int sp18;
    dGrass_anm_c* sp14 = getAnm();
    f32 temp_f30 = cM_scos(field_0x1d714);
    field_0x1d714 += (int)(40.0f + cM_rndF(290.0f));

    sp18 = 1.0f + ((1.0f - var_f31) * (2.0f + NREG_F(3)));

    f32 temp1 = 0.0625f;
    for (int i = 0; i < 16; sp14++, i++) {
        f32 temp_f28 = i * temp1;
        f32 temp2 = 500.0f + (500.0f * (i / 16));
        f32 temp_f29 = cLib_maxLimit<f32>(temp2, 2000.0f);
        f32 temp_f27_2 = 1.6f + (0.69999999f * cM_ssin(exec_count_dammy2));

        f32 temp3 = cM_ssin(exec_count_dammy + i * 3050);
        s16 sp8 = 0.69999999f * var_f31 * (temp_f29 + ((1.0f + (-0.2f * temp_f28)) * (10.0f * temp_f29 * (temp3 + temp_f27_2))));

        exec_count_dammy += (int)(s16)(525.0f * var_f31);
        exec_count_dammy2 += (int)(s16)(325.0f * var_f31);

        cLib_addCalcAngleS(&sp14->m_angX, (s16)sp8, sp18, 4000, 1);
        cLib_addCalcAngleS(&sp14->m_angY, (s16)cM_atan2s(temp_r29->x, temp_r29->z), 20, 4000, 1);
    }

    int sp10 = dComIfGp_roomControl_getStayNo();
    dGrass_data_c* var_r30 = m_room[sp10].getData();
    dComIfGs_Grass_hide_Set(0);

    if (var_r30 != NULL) {
        data_8052790d = 0;
        dComIfG_Ccsp()->SetMassAttr(40.0f, 120.0f, 11, 0);

        do {
            u16 spA = 0x89D7;
            if (var_r30->field_0x05 >= 7 && var_r30->field_0x05 <= 9) {
                spA = 0x89D6;
            } else if (var_r30->field_0x05 >= 4 && var_r30->field_0x05 <= 6) {
                spA = 0x89D8;
            }

            if (!cLib_checkBit<u8>(var_r30->field_0x01, 2)) {
                if (var_r30->field_0x02 >= 0) {
                    var_r30->hitCheck(sp10, spA);
                } else if (var_r30->field_0x02 < -2) {
                    var_r30->field_0x02++;
                }
            } else if (var_r30->field_0x02 >= 16) {
                daGrass_c::getGrass()->deleteAnm(var_r30->field_0x02);
                var_r30->field_0x02 = 15.0f * cM_rnd();
            }

            var_r30 = var_r30->mp_next;
        } while (var_r30 != NULL);
    } else {
        dComIfG_Ccsp()->SetMassAttr(40.0f, 40.0f, 11, 0);
    }
}

static f32 checkGroundY(cXyz& param_0) {
    dBgS_GndChk sp8;
    param_0.y += 50.0f;

    bool temp_r3 = fopAcM_gc_c::gndCheck(&param_0);
    f32 temp_f31 = fopAcM_gc_c::getGroundY();

    param_0.y -= 50.0f;

    f32 temp_f30;
    if (!temp_r3) {
        temp_f30 = param_0.y;
        return temp_f30;
    }

    return temp_f31;
}

void dGrass_packet_c::update() {
    static s16 mAngleZ[1500];

    dGrass_anm_c* anm_p = getAnm();
    for (int i = 0; i < 112; i++) {
        mDoMtx_stack_c::YrotS(anm_p->m_angY);
        mDoMtx_stack_c::XrotM(anm_p->m_angX);
        mDoMtx_stack_c::YrotM(-anm_p->m_angY);
        cMtx_copy(mDoMtx_stack_c::get(), anm_p->m_animMtx);
        anm_p++;
    }

    dGrass_data_c* data_p = getData();
    anm_p = getAnm();

    int var_r26 = 0;

    cXyz sp1C;
    f32 far = mDoLib_clipper::getFar();
    mDoLib_clipper::changeFar(far * 1.6363636f);

    for (int i = 0; i < 1500; i++) {
        if (data_p->m_state != 0) {
            if (data_p->m_state == 1 && var_r26 < 30) {
                data_p->m_pos.y = checkGroundY(data_p->m_pos);
                data_p->m_state = 2;
                var_r26++;
            }

            sp1C.set(data_p->m_pos.x, data_p->m_pos.y + 260.0f, data_p->m_pos.z);
            if (mDoLib_clipper::clip(j3dSys.getViewMtx(), sp1C, 260.0f)) {
                cLib_onBit<u8>(data_p->field_0x01, 2);
            } else {
                cLib_offBit<u8>(data_p->field_0x01, 2);

                if (data_p->field_0x02 >= 0) {
                    MtxP mtx = anm_p[data_p->field_0x02].m_animMtx;
                    mtx[0][3] = data_p->m_pos.x;
                    mtx[1][3] = data_p->m_pos.y;
                    mtx[2][3] = data_p->m_pos.z;

                    if (g_env_light.light_init_timer == 1) {
                        mAngleZ[i] = 0;
                    }

                    f32 temp_f2 = (((s16)data_p->m_pos.x * 3535) & 0xFFF) / 4096.0f;
                    temp_f2 = (temp_f2 + ((((s16)data_p->m_pos.z * 3535) & 0xFFF) / 4096.0f)) / 2;

                    f32 var_f31;
                    f32 var_f30;
                    if (data_p->field_0x05 >= 10) {
                        var_f31 = temp_f2 * 0.39999998f + 0.6f;
                        var_f30 = temp_f2 * 0.3f + 0.7f;
                    } else {
                        var_f31 = temp_f2 * 0.3f + 0.7f;
                        var_f30 = (temp_f2 * 0.3f + 0.7f) * 0.8f;
                    }

                    mDoMtx_stack_c::copy(mtx);

                    if (data_p->field_0x05 >= 7 && data_p->field_0x05 <= 9) {
                        mDoMtx_stack_c::ZrotM(mAngleZ[i]);
                        mDoMtx_stack_c::scaleM(var_f31, var_f30 - 0.22f, var_f31);
                        mDoMtx_stack_c::ZrotM(-mAngleZ[i]);

                        s16 ang = ((i + 1) & 0xF) * 5.0f + 162.0f;
                        mAngleZ[i] += ang;
                    } else {
                        if (data_p->field_0x05 >= 10 &&
                            memcmp(dComIfGp_getStartStageName(), "D_MN54", 6) != 0)
                        {
                            mDoMtx_stack_c::ZrotM(mAngleZ[i]);
                        }

                        mDoMtx_stack_c::scaleM(var_f31, var_f30, var_f31);

                        if (data_p->field_0x05 >= 10 &&
                            memcmp(dComIfGp_getStartStageName(), "D_MN54", 6) != 0)
                        {
                            mDoMtx_stack_c::ZrotM(-mAngleZ[i]);
                        }

                        if (data_p->field_0x05 >= 10) {
                            mDoMtx_stack_c::scaleM(2.0f, (i & 3) * 0.1f + 0.64f, 2.0f);
                        }

                        if (data_p->field_0x05 >= 10 &&
                            memcmp(dComIfGp_getStartStageName(), "D_MN54", 6) != 0)
                        {
                            mAngleZ[i] += (int)((((i + 1) & 0xF) * 25.0f + 3200.0f) * (dKyw_get_wind_pow() * dKyw_get_wind_pow() * dKyw_get_wind_pow()));
                        }
                    }

                    cMtx_concat(j3dSys.getViewMtx(), mDoMtx_stack_c::get(), data_p->m_modelMtx);
                } else {
                    mDoMtx_stack_c::transS(data_p->m_pos.x, data_p->m_pos.y, data_p->m_pos.z);
                    mDoMtx_stack_c::YrotM(i * 3535);

                    if (data_p->field_0x02 < -2) {
                        mDoMtx_stack_c::scaleM(1.0f, -data_p->field_0x02 / 40.0f, 1.0f);
                    }

                    f32 scale = ((((s16)data_p->m_pos.x * 3535) & 0xFFF) / 4096.0f) * 0.3f + 0.7f;
                    mDoMtx_stack_c::scaleM(scale, scale, scale);
                    cMtx_concat(j3dSys.getViewMtx(), mDoMtx_stack_c::get(), data_p->m_modelMtx);
                }
            }
        }
        data_p++;
    }

    mDoLib_clipper::resetFar();
    dComIfGd_getListPacket()->entryImm(this, 0);
}

void dGrass_packet_c::setData(dGrass_data_c* i_data, int i_dataNo, cXyz& i_pos, int i_roomNo,
                              u8 i_tableNo, u8 i_itemBitNo, s16 i_addCol, u8 param_7) {
    f32 y_pos;
    if (fopOvlpM_IsPeek()) {
        y_pos = checkGroundY(i_pos);
        i_data->m_state = 2;
    } else {
        y_pos = i_pos.y;
        i_data->m_state = 1;
    }

    i_data->field_0x01 = 2;
    i_data->field_0x02 = cM_rndF(15.0f);
    i_data->m_pos.set(i_pos.x, y_pos, i_pos.z);
    i_data->m_tableNo = i_tableNo;
    i_data->m_itemBitNo = i_itemBitNo;
    i_data->m_addCol = i_addCol;
    i_data->field_0x05 = param_7;

    m_room[i_roomNo].newData(i_data);
    m_dataNum = i_dataNo;
}

dGrass_data_c* dGrass_packet_c::newData(cXyz& i_pos, int i_roomNo, u8 i_tableNo, u8 i_itemBitNo,
                                        s16 i_addCol, u8 param_5) {
    dGrass_data_c* data_p = m_data + m_dataNum;

    for (int i = m_dataNum; i < 1500; i++) {
        if (data_p->m_state == 0) {
            setData(data_p, i, i_pos, i_roomNo, i_tableNo, i_itemBitNo, i_addCol, param_5);
            return data_p;
        }
        data_p++;
    }

    data_p = m_data;
    for (int i = 0; i < m_dataNum; i++) {
        if (data_p->m_state == 0) {
            setData(data_p, i, i_pos, i_roomNo, i_tableNo, i_itemBitNo, i_addCol, param_5);
            return data_p;
        }
        data_p++;
    }

    return NULL;
}

void dGrass_packet_c::deleteRoom(int i_roomNo) {
    m_room[i_roomNo].deleteData();
}

int dGrass_packet_c::newAnm() {
    dGrass_anm_c* anm_p = m_anm + 16;
    for (int i = 16; i < 112; i++) {
        if (anm_p->m_state == 0) {
            anm_p->m_state = 1;
            anm_p->m_angY = 0;
            anm_p->m_angX = 0;
            return i;
        }

        anm_p++;
    }

    return -1;
}

void dGrass_packet_c::setAnm(int i_idx, s16) {
    dGrass_anm_c* anm_p = m_anm + i_idx;

    anm_p->m_state = 1;
    anm_p->m_angY = 0;
    anm_p->m_angX = 0;
}
