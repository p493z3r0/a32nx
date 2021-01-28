#include "FlyByWire.h"
#include "FlyByWire_private.h"
#include "look1_binlxpw.h"
#include "look2_binlxpw.h"

const uint8_T FlyByWire_IN_InAir = 1U;
const uint8_T FlyByWire_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T FlyByWire_IN_OnGround = 2U;
const uint8_T FlyByWire_IN_Flare_Reduce_Theta_c = 1U;
const uint8_T FlyByWire_IN_Flare_Set_Rate = 2U;
const uint8_T FlyByWire_IN_Flare_Store_Theta_c_deg = 3U;
const uint8_T FlyByWire_IN_Flight_High = 4U;
const uint8_T FlyByWire_IN_Flight_Low = 5U;
const uint8_T FlyByWire_IN_Ground = 6U;
const uint8_T FlyByWire_IN_frozen = 1U;
const uint8_T FlyByWire_IN_running = 2U;
const uint8_T FlyByWire_IN_Flight = 1U;
const uint8_T FlyByWire_IN_FlightToGroundTransition = 2U;
const uint8_T FlyByWire_IN_Ground_p = 3U;
const uint8_T FlyByWire_IN_automatic = 1U;
const uint8_T FlyByWire_IN_manual = 2U;
const uint8_T FlyByWire_IN_reset = 3U;
const uint8_T FlyByWire_IN_tracking = 4U;
const uint8_T FlyByWire_IN_flight_clean = 1U;
const uint8_T FlyByWire_IN_flight_flaps = 2U;
const uint8_T FlyByWire_IN_ground = 3U;
const uint8_T FlyByWire_IN_OFF = 1U;
const uint8_T FlyByWire_IN_ON = 2U;
const uint8_T FlyByWire_IN_FlightMode = 1U;
const uint8_T FlyByWire_IN_GroundMode = 2U;
const fbw_output FlyByWire_rtZfbw_output = {
  {
    {
      0.0,
      0.0,
      0.0
    },

    {
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0
    },

    {
      0.0,
      0.0
    },

    {
      0.0,
      0.0,
      0.0
    }
  },

  {
    {
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0,
      false,
      false,
      0.0,
      false,
      0.0,
      0.0,
      0.0,
      0.0,
      0.0
    },

    {
      0.0,
      0.0
    },

    {
      0.0,
      0.0,
      0.0
    },

    {
      0.0
    },

    {
      0.0
    },

    {
      0.0,
      0.0
    }
  },

  {
    {
      0.0,
      0.0,
      0.0,
      0.0,
      false,
      0.0
    },

    {
      0.0,
      0.0,
      0.0,
      0.0
    },

    {
      0.0,
      0.0,
      0.0
    }
  },

  {
    0.0,
    0.0,
    false,
    0.0,
    0.0,
    0.0,
    false
  }
} ;

const fbw_input FlyByWire_rtZfbw_input = { { 0.0, 0.0 }, { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } };

void FlyByWireModelClass::step()
{
  real_T Theta;
  real_T Phi;
  real_T result[3];
  real_T result_0[3];
  real_T rtb_Limiterxi;
  real_T rtb_Limiterxi1;
  real_T rtb_LimiteriH;
  real_T rtb_Divide_ke;
  real_T rtb_Product_a;
  real_T rtb_Product3;
  real_T rtb_Sum1_g0;
  real_T rtb_Gainpk4;
  real_T rtb_GainTheta;
  real_T rtb_GainPhi;
  real_T rtb_Gainqk;
  real_T rtb_Gain;
  real_T rtb_Gainpk;
  boolean_T rtb_AND;
  boolean_T rtb_NOT2;
  int32_T rtb_on_ground;
  int32_T rtb_BusAssignment_a_sim_data_computed_tracking_mode_on;
  real_T rtb_BusAssignment_a_sim_input_delta_zeta_pos;
  int32_T rtb_in_rotation;
  int32_T rtb_in_flare;
  real_T rtb_nz_limit_up_g;
  int32_T rtb_nz_limit_lo_g;
  boolean_T rtb_eta_trim_deg_should_freeze;
  real_T rtb_eta_trim_deg_reset_deg;
  boolean_T rtb_eta_trim_deg_should_write;
  real_T rtb_eta_trim_deg_rate_limit_up_deg_s;
  real_T rtb_eta_trim_deg_rate_limit_lo_deg_s;
  real_T rtb_BusAssignment_c_pitch_data_computed_delta_eta_deg;
  real_T rtb_Gain_ku;
  real_T rtb_Gain_d;
  real_T rtb_Sum2;
  real_T rtb_BusAssignment_m_pitch_output_eta_deg;
  real_T rtb_Gain1_l;
  int32_T rtb_in_flight;
  real_T rtb_BusAssignment_p_roll_data_computed_delta_xi_deg;
  real_T rtb_BusAssignment_e_roll_law_normal_xi_deg;
  real_T rtb_ManualSwitch;
  real_T rtb_Gain1_h;
  real_T rtb_Switch_c;
  real_T rtb_Saturation2;
  real_T result_tmp;
  real_T tmp[9];
  real_T u1;
  FlyByWire_DWork.Delay_DSTATE += FlyByWire_U.in.time.dt;
  rtb_GainTheta = FlyByWire_P.GainTheta_Gain * FlyByWire_U.in.data.Theta_deg;
  rtb_GainPhi = FlyByWire_P.GainPhi_Gain * FlyByWire_U.in.data.Phi_deg;
  rtb_Gainqk = FlyByWire_P.Gain_Gain_n * FlyByWire_U.in.data.q_rad_s * FlyByWire_P.Gainqk_Gain;
  rtb_Gain = FlyByWire_P.Gain_Gain_l * FlyByWire_U.in.data.r_rad_s;
  rtb_Gainpk = FlyByWire_P.Gain_Gain_a * FlyByWire_U.in.data.p_rad_s * FlyByWire_P.Gainpk_Gain;
  Theta = 0.017453292519943295 * rtb_GainTheta;
  Phi = 0.017453292519943295 * rtb_GainPhi;
  result_tmp = std::tan(Theta);
  rtb_Gainpk4 = std::sin(Phi);
  Phi = std::cos(Phi);
  tmp[0] = 1.0;
  tmp[3] = rtb_Gainpk4 * result_tmp;
  tmp[6] = Phi * result_tmp;
  tmp[1] = 0.0;
  tmp[4] = Phi;
  tmp[7] = -rtb_Gainpk4;
  tmp[2] = 0.0;
  rtb_Limiterxi1 = 1.0 / std::cos(Theta);
  tmp[5] = rtb_Limiterxi1 * rtb_Gainpk4;
  tmp[8] = rtb_Limiterxi1 * Phi;
  for (rtb_on_ground = 0; rtb_on_ground < 3; rtb_on_ground++) {
    result[rtb_on_ground] = tmp[rtb_on_ground + 6] * rtb_Gain + (tmp[rtb_on_ground + 3] * rtb_Gainqk + tmp[rtb_on_ground]
      * rtb_Gainpk);
  }

  Theta = 0.017453292519943295 * rtb_GainTheta;
  Phi = 0.017453292519943295 * rtb_GainPhi;
  result_tmp = std::tan(Theta);
  rtb_Gainpk4 = std::sin(Phi);
  Phi = std::cos(Phi);
  tmp[0] = 1.0;
  tmp[3] = rtb_Gainpk4 * result_tmp;
  tmp[6] = Phi * result_tmp;
  tmp[1] = 0.0;
  tmp[4] = Phi;
  tmp[7] = -rtb_Gainpk4;
  tmp[2] = 0.0;
  rtb_Limiterxi1 = 1.0 / std::cos(Theta);
  tmp[5] = rtb_Limiterxi1 * rtb_Gainpk4;
  tmp[8] = rtb_Limiterxi1 * Phi;
  rtb_Gainpk4 = FlyByWire_P.Gain_Gain_nm * FlyByWire_U.in.data.p_dot_rad_s2 * FlyByWire_P.Gainpk1_Gain;
  Theta = FlyByWire_P.Gain_Gain_e * FlyByWire_U.in.data.q_dot_rad_s2 * FlyByWire_P.Gainqk1_Gain;
  result_tmp = FlyByWire_P.Gain_Gain_aw * FlyByWire_U.in.data.r_dot_rad_s2;
  for (rtb_on_ground = 0; rtb_on_ground < 3; rtb_on_ground++) {
    result_0[rtb_on_ground] = tmp[rtb_on_ground + 6] * result_tmp + (tmp[rtb_on_ground + 3] * Theta + tmp[rtb_on_ground]
      * rtb_Gainpk4);
  }

  rtb_Gainpk4 = FlyByWire_P.Gainpk4_Gain * FlyByWire_U.in.data.eta_pos;
  rtb_Product3 = FlyByWire_P.Gainpk2_Gain * FlyByWire_U.in.data.eta_trim_deg;
  rtb_LimiteriH = FlyByWire_P.Gain1_Gain_h * FlyByWire_U.in.data.gear_animation_pos_1 - FlyByWire_P.Constant_Value_g;
  if (rtb_LimiteriH > FlyByWire_P.Saturation1_UpperSat_g) {
    rtb_LimiteriH = FlyByWire_P.Saturation1_UpperSat_g;
  } else {
    if (rtb_LimiteriH < FlyByWire_P.Saturation1_LowerSat_j) {
      rtb_LimiteriH = FlyByWire_P.Saturation1_LowerSat_j;
    }
  }

  rtb_Switch_c = FlyByWire_P.Gain2_Gain_a * FlyByWire_U.in.data.gear_animation_pos_2 - FlyByWire_P.Constant_Value_g;
  if (rtb_Switch_c > FlyByWire_P.Saturation2_UpperSat_b) {
    rtb_Switch_c = FlyByWire_P.Saturation2_UpperSat_b;
  } else {
    if (rtb_Switch_c < FlyByWire_P.Saturation2_LowerSat_g) {
      rtb_Switch_c = FlyByWire_P.Saturation2_LowerSat_g;
    }
  }

  FlyByWire_Y.out.sim.data.gear_strut_compression_1 = rtb_LimiteriH;
  FlyByWire_Y.out.sim.data.gear_strut_compression_2 = rtb_Switch_c;
  Theta = FlyByWire_P.Gaineta_Gain * FlyByWire_U.in.input.delta_eta_pos;
  if (FlyByWire_DWork.is_active_c1_FlyByWire == 0U) {
    FlyByWire_DWork.is_active_c1_FlyByWire = 1U;
    FlyByWire_DWork.is_c1_FlyByWire = FlyByWire_IN_OnGround;
    rtb_on_ground = 1;
  } else if (FlyByWire_DWork.is_c1_FlyByWire == FlyByWire_IN_InAir) {
    if ((rtb_LimiteriH > 0.1) || (rtb_Switch_c > 0.1)) {
      FlyByWire_DWork.is_c1_FlyByWire = FlyByWire_IN_OnGround;
      rtb_on_ground = 1;
    } else {
      rtb_on_ground = 0;
    }
  } else {
    if ((rtb_LimiteriH == 0.0) && (rtb_Switch_c == 0.0)) {
      FlyByWire_DWork.is_c1_FlyByWire = FlyByWire_IN_InAir;
      rtb_on_ground = 0;
    } else {
      rtb_on_ground = 1;
    }
  }

  rtb_NOT2 = ((FlyByWire_U.in.data.autopilot_master_on != 0.0) || (FlyByWire_U.in.data.slew_on != 0.0) ||
              (FlyByWire_U.in.data.pause_on != 0.0) || (FlyByWire_U.in.data.tracking_mode_on_override != 0.0));
  FlyByWire_Y.out.sim.data.eta_trim_deg = rtb_Product3;
  result_tmp = FlyByWire_P.Gainpk3_Gain * FlyByWire_U.in.data.zeta_trim_pos;
  Phi = FlyByWire_P.Gainxi_Gain * FlyByWire_U.in.input.delta_xi_pos;
  rtb_BusAssignment_a_sim_input_delta_zeta_pos = FlyByWire_P.Gainxi1_Gain * FlyByWire_U.in.input.delta_zeta_pos;
  rtb_BusAssignment_a_sim_data_computed_tracking_mode_on = ((FlyByWire_U.in.data.autopilot_master_on != 0.0) ||
    (FlyByWire_U.in.data.slew_on != 0.0) || (FlyByWire_U.in.data.pause_on != 0.0) ||
    (FlyByWire_U.in.data.tracking_mode_on_override != 0.0));
  if (FlyByWire_DWork.is_active_c3_FlyByWire == 0U) {
    FlyByWire_DWork.is_active_c3_FlyByWire = 1U;
    FlyByWire_DWork.is_c3_FlyByWire = FlyByWire_IN_Ground_p;
    FlyByWire_B.in_flight = 0.0;
  } else {
    switch (FlyByWire_DWork.is_c3_FlyByWire) {
     case FlyByWire_IN_Flight:
      if ((rtb_on_ground == 1) && (rtb_GainTheta < 2.5)) {
        FlyByWire_DWork.on_ground_time = FlyByWire_U.in.time.simulation_time;
        FlyByWire_DWork.is_c3_FlyByWire = FlyByWire_IN_FlightToGroundTransition;
      } else {
        FlyByWire_B.in_flight = 1.0;
      }
      break;

     case FlyByWire_IN_FlightToGroundTransition:
      if (FlyByWire_U.in.time.simulation_time - FlyByWire_DWork.on_ground_time >= 5.0) {
        FlyByWire_DWork.is_c3_FlyByWire = FlyByWire_IN_Ground_p;
        FlyByWire_B.in_flight = 0.0;
      } else {
        if ((rtb_on_ground == 0) || (rtb_GainTheta >= 2.5)) {
          FlyByWire_DWork.on_ground_time = 0.0;
          FlyByWire_DWork.is_c3_FlyByWire = FlyByWire_IN_Flight;
          FlyByWire_B.in_flight = 1.0;
        }
      }
      break;

     default:
      if (((rtb_on_ground == 0) && (rtb_GainTheta > 8.0)) || (FlyByWire_U.in.data.H_radio_ft > 400.0)) {
        FlyByWire_DWork.on_ground_time = 0.0;
        FlyByWire_DWork.is_c3_FlyByWire = FlyByWire_IN_Flight;
        FlyByWire_B.in_flight = 1.0;
      } else {
        FlyByWire_B.in_flight = 0.0;
      }
      break;
    }
  }

  if (FlyByWire_B.in_flight > FlyByWire_P.Saturation_UpperSat_er) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation_UpperSat_er;
  } else if (FlyByWire_B.in_flight < FlyByWire_P.Saturation_LowerSat_a) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation_LowerSat_a;
  } else {
    rtb_Limiterxi1 = FlyByWire_B.in_flight;
  }

  rtb_Limiterxi1 -= FlyByWire_DWork.Delay_DSTATE_n;
  u1 = FlyByWire_P.RateLimiterVariableTs_up * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs_lo;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_n += rtb_Limiterxi1;
  if (FlyByWire_DWork.is_active_c6_FlyByWire == 0U) {
    FlyByWire_DWork.is_active_c6_FlyByWire = 1U;
    FlyByWire_DWork.is_c6_FlyByWire = FlyByWire_IN_OFF;
    rtb_in_rotation = 0;
  } else if (FlyByWire_DWork.is_c6_FlyByWire == FlyByWire_IN_OFF) {
    if ((FlyByWire_DWork.Delay_DSTATE_n == 0.0) && (FlyByWire_U.in.data.V_tas_kn > 70.0) &&
        ((FlyByWire_U.in.data.thrust_lever_1_pos >= 95.0) || (FlyByWire_U.in.data.thrust_lever_2_pos >= 95.0))) {
      FlyByWire_DWork.is_c6_FlyByWire = FlyByWire_IN_ON;
      rtb_in_rotation = 1;
    } else {
      rtb_in_rotation = 0;
    }
  } else {
    if ((FlyByWire_DWork.Delay_DSTATE_n == 1.0) || (FlyByWire_U.in.data.H_radio_ft > 400.0) ||
        ((FlyByWire_U.in.data.V_tas_kn < 70.0) && ((FlyByWire_U.in.data.thrust_lever_1_pos < 95.0) ||
          (FlyByWire_U.in.data.thrust_lever_2_pos < 95.0)))) {
      FlyByWire_DWork.is_c6_FlyByWire = FlyByWire_IN_OFF;
      rtb_in_rotation = 0;
    } else {
      rtb_in_rotation = 1;
    }
  }

  rtb_Limiterxi = FlyByWire_U.in.time.dt * FlyByWire_P.LagFilter_C1;
  rtb_Limiterxi1 = rtb_Limiterxi + FlyByWire_P.Constant_Value_f;
  FlyByWire_DWork.Delay1_DSTATE = 1.0 / rtb_Limiterxi1 * (FlyByWire_P.Constant_Value_f - rtb_Limiterxi) *
    FlyByWire_DWork.Delay1_DSTATE + (rtb_GainTheta + FlyByWire_DWork.Delay_DSTATE_j) * (rtb_Limiterxi / rtb_Limiterxi1);
  if (FlyByWire_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch = FlyByWire_P.Constant1_Value_f;
  } else {
    rtb_ManualSwitch = FlyByWire_P.Constant_Value_jz;
  }

  if (FlyByWire_DWork.is_active_c2_FlyByWire == 0U) {
    FlyByWire_DWork.is_active_c2_FlyByWire = 1U;
    FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Ground;
    rtb_in_flare = 0;
    FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
    FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
  } else {
    switch (FlyByWire_DWork.is_c2_FlyByWire) {
     case FlyByWire_IN_Flare_Reduce_Theta_c:
      if (FlyByWire_B.in_flight == 0.0) {
        FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Ground;
        rtb_in_flare = 0;
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
      } else if ((FlyByWire_U.in.data.H_radio_ft > 50.0) && (rtb_ManualSwitch == 0.0)) {
        FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Flight_Low;
        rtb_in_flare = 0;
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
      } else {
        rtb_in_flare = 1;
        FlyByWire_B.flare_Theta_c_deg = -2.0;
      }
      break;

     case FlyByWire_IN_Flare_Set_Rate:
      if (FlyByWire_P.ManualSwitch1_CurrentSetting == 1) {
        rtb_Limiterxi1 = FlyByWire_P.Constant1_Value_f;
      } else {
        rtb_Limiterxi1 = FlyByWire_P.Constant_Value_jz;
      }

      if ((FlyByWire_U.in.data.H_radio_ft <= 30.0) || (rtb_Limiterxi1 == 1.0)) {
        FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Flare_Reduce_Theta_c;
        rtb_in_flare = 1;
        FlyByWire_B.flare_Theta_c_deg = -2.0;
      } else if ((FlyByWire_U.in.data.H_radio_ft > 50.0) && (rtb_ManualSwitch == 0.0)) {
        FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Flight_Low;
        rtb_in_flare = 0;
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
      } else {
        rtb_in_flare = 1;
      }
      break;

     case FlyByWire_IN_Flare_Store_Theta_c_deg:
      if ((FlyByWire_U.in.data.H_radio_ft > 50.0) && (rtb_ManualSwitch == 0.0)) {
        FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Flight_Low;
        rtb_in_flare = 0;
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
      } else {
        FlyByWire_B.flare_Theta_c_rate_deg_s = -(FlyByWire_DWork.Delay1_DSTATE + 2.0) / 8.0;
        FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Flare_Set_Rate;
        rtb_in_flare = 1;
      }
      break;

     case FlyByWire_IN_Flight_High:
      if ((FlyByWire_U.in.data.H_radio_ft <= 50.0) || (rtb_ManualSwitch == 1.0)) {
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Flare_Store_Theta_c_deg;
        rtb_in_flare = 1;
      } else {
        rtb_in_flare = 0;
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
      }
      break;

     case FlyByWire_IN_Flight_Low:
      if (FlyByWire_U.in.data.H_radio_ft > 50.0) {
        FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Flight_High;
        rtb_in_flare = 0;
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
      } else {
        rtb_in_flare = 0;
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
      }
      break;

     default:
      if (FlyByWire_B.in_flight == 1.0) {
        FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_Flight_Low;
        rtb_in_flare = 0;
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
      } else {
        rtb_in_flare = 0;
        FlyByWire_B.flare_Theta_c_deg = FlyByWire_DWork.Delay1_DSTATE;
        FlyByWire_B.flare_Theta_c_rate_deg_s = -3.0;
      }
      break;
    }
  }

  if (rtb_in_rotation > FlyByWire_P.Saturation1_UpperSat_f) {
    rtb_ManualSwitch = FlyByWire_P.Saturation1_UpperSat_f;
  } else if (rtb_in_rotation < FlyByWire_P.Saturation1_LowerSat_p) {
    rtb_ManualSwitch = FlyByWire_P.Saturation1_LowerSat_p;
  } else {
    rtb_ManualSwitch = rtb_in_rotation;
  }

  rtb_Limiterxi1 = rtb_ManualSwitch - FlyByWire_DWork.Delay_DSTATE_k;
  u1 = FlyByWire_P.RateLimiterVariableTs1_up * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs1_lo;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_k += rtb_Limiterxi1;
  if (FlyByWire_DWork.is_active_c7_FlyByWire == 0U) {
    FlyByWire_DWork.is_active_c7_FlyByWire = 1U;
    FlyByWire_DWork.is_c7_FlyByWire = FlyByWire_IN_ground;
    rtb_eta_trim_deg_rate_limit_up_deg_s = 0.7;
    rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.7;
    rtb_nz_limit_up_g = 2.0;
    rtb_nz_limit_lo_g = 0;
  } else {
    switch (FlyByWire_DWork.is_c7_FlyByWire) {
     case FlyByWire_IN_flight_clean:
      if (FlyByWire_U.in.data.flaps_handle_index != 0.0) {
        FlyByWire_DWork.is_c7_FlyByWire = FlyByWire_IN_flight_flaps;
        rtb_eta_trim_deg_rate_limit_up_deg_s = 0.7;
        rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.7;
        rtb_nz_limit_up_g = 2.0;
        rtb_nz_limit_lo_g = 0;
      } else if ((FlyByWire_B.in_flight == 0.0) && (FlyByWire_U.in.data.flaps_handle_index == 0.0)) {
        FlyByWire_DWork.is_c7_FlyByWire = FlyByWire_IN_ground;
        rtb_eta_trim_deg_rate_limit_up_deg_s = 0.7;
        rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.7;
        rtb_nz_limit_up_g = 2.0;
        rtb_nz_limit_lo_g = 0;
      } else {
        rtb_eta_trim_deg_rate_limit_up_deg_s = 0.3;
        rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.3;
        rtb_nz_limit_up_g = 2.5;
        rtb_nz_limit_lo_g = -1;
      }
      break;

     case FlyByWire_IN_flight_flaps:
      if (FlyByWire_U.in.data.flaps_handle_index == 0.0) {
        FlyByWire_DWork.is_c7_FlyByWire = FlyByWire_IN_flight_clean;
        rtb_eta_trim_deg_rate_limit_up_deg_s = 0.3;
        rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.3;
        rtb_nz_limit_up_g = 2.5;
        rtb_nz_limit_lo_g = -1;
      } else if (FlyByWire_B.in_flight == 0.0) {
        FlyByWire_DWork.is_c7_FlyByWire = FlyByWire_IN_ground;
        rtb_eta_trim_deg_rate_limit_up_deg_s = 0.7;
        rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.7;
        rtb_nz_limit_up_g = 2.0;
        rtb_nz_limit_lo_g = 0;
      } else {
        rtb_eta_trim_deg_rate_limit_up_deg_s = 0.7;
        rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.7;
        rtb_nz_limit_up_g = 2.0;
        rtb_nz_limit_lo_g = 0;
      }
      break;

     default:
      if ((FlyByWire_B.in_flight != 0.0) && (FlyByWire_U.in.data.flaps_handle_index == 0.0)) {
        FlyByWire_DWork.is_c7_FlyByWire = FlyByWire_IN_flight_clean;
        rtb_eta_trim_deg_rate_limit_up_deg_s = 0.3;
        rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.3;
        rtb_nz_limit_up_g = 2.5;
        rtb_nz_limit_lo_g = -1;
      } else if ((FlyByWire_B.in_flight != 0.0) && (FlyByWire_U.in.data.flaps_handle_index != 0.0)) {
        FlyByWire_DWork.is_c7_FlyByWire = FlyByWire_IN_flight_flaps;
        rtb_eta_trim_deg_rate_limit_up_deg_s = 0.7;
        rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.7;
        rtb_nz_limit_up_g = 2.0;
        rtb_nz_limit_lo_g = 0;
      } else {
        rtb_eta_trim_deg_rate_limit_up_deg_s = 0.7;
        rtb_eta_trim_deg_rate_limit_lo_deg_s = -0.7;
        rtb_nz_limit_up_g = 2.0;
        rtb_nz_limit_lo_g = 0;
      }
      break;
    }
  }

  if (FlyByWire_DWork.is_active_c9_FlyByWire == 0U) {
    FlyByWire_DWork.is_active_c9_FlyByWire = 1U;
    FlyByWire_DWork.is_c9_FlyByWire = FlyByWire_IN_running;
    rtb_eta_trim_deg_should_freeze = false;
  } else if (FlyByWire_DWork.is_c9_FlyByWire == FlyByWire_IN_frozen) {
    if ((rtb_in_flare == 0) && (FlyByWire_U.in.data.nz_g < 1.25) && (FlyByWire_U.in.data.nz_g > 0.5) && (std::abs
         (rtb_GainPhi) <= 30.0)) {
      FlyByWire_DWork.is_c9_FlyByWire = FlyByWire_IN_running;
      rtb_eta_trim_deg_should_freeze = false;
    } else {
      rtb_eta_trim_deg_should_freeze = true;
    }
  } else {
    if ((rtb_in_flare != 0) || (FlyByWire_U.in.data.nz_g >= 1.25) || (FlyByWire_U.in.data.nz_g <= 0.5) || (std::abs
         (rtb_GainPhi) > 30.0)) {
      FlyByWire_DWork.is_c9_FlyByWire = FlyByWire_IN_frozen;
      rtb_eta_trim_deg_should_freeze = true;
    } else {
      rtb_eta_trim_deg_should_freeze = false;
    }
  }

  if (FlyByWire_DWork.is_active_c8_FlyByWire == 0U) {
    FlyByWire_DWork.is_active_c8_FlyByWire = 1U;
    FlyByWire_DWork.is_c8_FlyByWire = FlyByWire_IN_manual;
    rtb_NOT2 = true;
    rtb_eta_trim_deg_reset_deg = rtb_Product3;
    rtb_eta_trim_deg_should_write = false;
  } else {
    switch (FlyByWire_DWork.is_c8_FlyByWire) {
     case FlyByWire_IN_automatic:
      if (FlyByWire_B.in_flight == 0.0) {
        FlyByWire_DWork.is_c8_FlyByWire = FlyByWire_IN_reset;
        rtb_NOT2 = true;
        rtb_eta_trim_deg_reset_deg = 0.0;
        rtb_eta_trim_deg_should_write = true;
      } else if (rtb_NOT2) {
        FlyByWire_DWork.is_c8_FlyByWire = FlyByWire_IN_tracking;
        rtb_NOT2 = true;
        rtb_eta_trim_deg_reset_deg = rtb_Product3;
        rtb_eta_trim_deg_should_write = false;
      } else {
        rtb_NOT2 = false;
        rtb_eta_trim_deg_reset_deg = rtb_Product3;
        rtb_eta_trim_deg_should_write = true;
      }
      break;

     case FlyByWire_IN_manual:
      if (FlyByWire_B.in_flight != 0.0) {
        FlyByWire_DWork.is_c8_FlyByWire = FlyByWire_IN_automatic;
        rtb_NOT2 = false;
        rtb_eta_trim_deg_reset_deg = rtb_Product3;
        rtb_eta_trim_deg_should_write = true;
      } else {
        rtb_NOT2 = true;
        rtb_eta_trim_deg_reset_deg = rtb_Product3;
        rtb_eta_trim_deg_should_write = false;
      }
      break;

     case FlyByWire_IN_reset:
      if ((FlyByWire_B.in_flight == 0.0) && (rtb_Product3 == 0.0)) {
        FlyByWire_DWork.is_c8_FlyByWire = FlyByWire_IN_manual;
        rtb_NOT2 = true;
        rtb_eta_trim_deg_reset_deg = rtb_Product3;
        rtb_eta_trim_deg_should_write = false;
      } else {
        rtb_NOT2 = true;
        rtb_eta_trim_deg_reset_deg = 0.0;
        rtb_eta_trim_deg_should_write = true;
      }
      break;

     default:
      if (!rtb_NOT2) {
        FlyByWire_DWork.is_c8_FlyByWire = FlyByWire_IN_automatic;
        rtb_NOT2 = false;
        rtb_eta_trim_deg_reset_deg = rtb_Product3;
        rtb_eta_trim_deg_should_write = true;
      } else {
        rtb_NOT2 = true;
        rtb_eta_trim_deg_reset_deg = rtb_Product3;
        rtb_eta_trim_deg_should_write = false;
      }
      break;
    }
  }

  rtb_Limiterxi1 = FlyByWire_B.flare_Theta_c_deg - FlyByWire_DWork.Delay_DSTATE_a;
  u1 = std::abs(FlyByWire_B.flare_Theta_c_rate_deg_s) * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_B.flare_Theta_c_rate_deg_s;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_a += rtb_Limiterxi1;
  rtb_BusAssignment_c_pitch_data_computed_delta_eta_deg = FlyByWire_P.Gain_Gain_d * Theta;
  rtb_Limiterxi1 = Theta - FlyByWire_DWork.Delay_DSTATE_f;
  u1 = FlyByWire_P.RateLimiterVariableTs_up_d * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs_lo_d;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_f += rtb_Limiterxi1;
  if (FlyByWire_DWork.Delay_DSTATE_f > FlyByWire_P.Saturation3_UpperSat) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation3_UpperSat;
  } else if (FlyByWire_DWork.Delay_DSTATE_f < FlyByWire_P.Saturation3_LowerSat) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation3_LowerSat;
  } else {
    rtb_Limiterxi1 = FlyByWire_DWork.Delay_DSTATE_f;
  }

  rtb_Switch_c = look1_binlxpw(look2_binlxpw(rtb_GainTheta, FlyByWire_U.in.data.H_radio_ft,
    FlyByWire_P.uDLookupTable_bp01Data, FlyByWire_P.uDLookupTable_bp02Data, FlyByWire_P.uDLookupTable_tableData,
    FlyByWire_P.uDLookupTable_maxIndex, 5U) * rtb_Limiterxi1 + FlyByWire_DWork.Delay_DSTATE_f,
    FlyByWire_P.PitchRateDemand_bp01Data, FlyByWire_P.PitchRateDemand_tableData, 2U);
  rtb_ManualSwitch = FlyByWire_P.DiscreteDerivativeVariableTs_Gain * rtb_Switch_c;
  rtb_LimiteriH = result[1] - rtb_Switch_c;
  rtb_Gain_ku = FlyByWire_P.Gain_Gain_h * rtb_LimiteriH;
  rtb_Gain_d = FlyByWire_P.Gain1_Gain_i * rtb_LimiteriH * FlyByWire_P.DiscreteDerivativeVariableTs_Gain_b;
  rtb_Sum2 = FlyByWire_P.Gain5_Gain * result_0[1] + result[1];
  rtb_LimiteriH = FlyByWire_U.in.time.dt * FlyByWire_P.LagFilter_C1_i;
  rtb_Limiterxi = rtb_LimiteriH + FlyByWire_P.Constant_Value_n;
  FlyByWire_DWork.Delay1_DSTATE_p = 1.0 / rtb_Limiterxi * (FlyByWire_P.Constant_Value_n - rtb_LimiteriH) *
    FlyByWire_DWork.Delay1_DSTATE_p + (rtb_Sum2 + FlyByWire_DWork.Delay_DSTATE_fz) * (rtb_LimiteriH / rtb_Limiterxi);
  rtb_LimiteriH = (((((rtb_Gain_d - FlyByWire_DWork.Delay_DSTATE_fv) / FlyByWire_U.in.time.dt + rtb_Gain_ku) *
                     FlyByWire_P.Gain1_Gain_a + (rtb_ManualSwitch - FlyByWire_DWork.Delay_DSTATE_ky) /
                     FlyByWire_U.in.time.dt * FlyByWire_P.Gain3_Gain_p) + (FlyByWire_DWork.Delay1_DSTATE_p -
    rtb_Switch_c) * FlyByWire_P.Gain4_Gain_g) + FlyByWire_P.Gain6_Gain * result_0[1]) *
    FlyByWire_P.DiscreteTimeIntegratorVariableTs_Gain * FlyByWire_U.in.time.dt;
  if (((Theta <= FlyByWire_P.Constant_Value_j) && (rtb_on_ground != 0)) || (FlyByWire_DWork.Delay_DSTATE_k == 0.0) ||
      (rtb_BusAssignment_a_sim_data_computed_tracking_mode_on != 0)) {
    FlyByWire_DWork.icLoad = 1U;
  }

  if (FlyByWire_DWork.icLoad != 0) {
    FlyByWire_DWork.Delay_DSTATE_e = FlyByWire_P.Constant_Value_h - rtb_LimiteriH;
  }

  rtb_LimiteriH += FlyByWire_DWork.Delay_DSTATE_e;
  if (rtb_LimiteriH > FlyByWire_P.DiscreteTimeIntegratorVariableTs_UpperLimit) {
    FlyByWire_DWork.Delay_DSTATE_e = FlyByWire_P.DiscreteTimeIntegratorVariableTs_UpperLimit;
  } else if (rtb_LimiteriH < FlyByWire_P.DiscreteTimeIntegratorVariableTs_LowerLimit) {
    FlyByWire_DWork.Delay_DSTATE_e = FlyByWire_P.DiscreteTimeIntegratorVariableTs_LowerLimit;
  } else {
    FlyByWire_DWork.Delay_DSTATE_e = rtb_LimiteriH;
  }

  FlyByWire_Y.out.pitch.law_rotation.qk_c_deg_s = rtb_Switch_c;
  if (rtb_on_ground > FlyByWire_P.Switch_Threshold_h) {
    if (rtb_BusAssignment_c_pitch_data_computed_delta_eta_deg > FlyByWire_P.Saturation_UpperSat_g) {
      rtb_Switch_c = FlyByWire_P.Saturation_UpperSat_g;
    } else if (rtb_BusAssignment_c_pitch_data_computed_delta_eta_deg < FlyByWire_P.Saturation_LowerSat_p) {
      rtb_Switch_c = FlyByWire_P.Saturation_LowerSat_p;
    } else {
      rtb_Switch_c = rtb_BusAssignment_c_pitch_data_computed_delta_eta_deg;
    }
  } else {
    rtb_Switch_c = FlyByWire_P.Constant1_Value;
  }

  rtb_Gain_ku = FlyByWire_DWork.Delay_DSTATE_e + rtb_Switch_c;
  rtb_Switch_c = std::cos(FlyByWire_P.Gain1_Gain_p * rtb_GainTheta);
  rtb_LimiteriH = rtb_Switch_c / std::cos(FlyByWire_P.Gain1_Gain_pa * rtb_GainPhi);
  rtb_Limiterxi = FlyByWire_P.Gain1_Gain_j * result[1] * (FlyByWire_P.Gain_Gain_dc * FlyByWire_P.Vm_currentms_Value) +
    (FlyByWire_U.in.data.nz_g - rtb_LimiteriH);
  if (rtb_GainPhi > FlyByWire_P.Saturation_UpperSat_d) {
    rtb_Divide_ke = FlyByWire_P.Saturation_UpperSat_d;
  } else if (rtb_GainPhi < FlyByWire_P.Saturation_LowerSat_pr) {
    rtb_Divide_ke = FlyByWire_P.Saturation_LowerSat_pr;
  } else {
    rtb_Divide_ke = rtb_GainPhi;
  }

  rtb_Divide_ke = rtb_Switch_c / std::cos(FlyByWire_P.Gain1_Gain_b * rtb_Divide_ke);
  rtb_Limiterxi1 = FlyByWire_U.in.data.autopilot_custom_Theta_c_deg - FlyByWire_DWork.Delay_DSTATE_m;
  u1 = FlyByWire_P.RateLimiterVariableTs1_up_k * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs1_lo_h;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_m += rtb_Limiterxi1;
  rtb_Limiterxi1 = Theta - FlyByWire_DWork.Delay_DSTATE_d;
  u1 = FlyByWire_P.RateLimiterVariableTs_up_f * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs_lo_f;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_d += rtb_Limiterxi1;
  if (FlyByWire_U.in.data.autopilot_custom_on > FlyByWire_P.Switch1_Threshold_k) {
    rtb_Switch_c = (FlyByWire_DWork.Delay_DSTATE_m - rtb_GainTheta) * FlyByWire_P.Gain4_Gain;
  } else {
    rtb_Gain1_h = FlyByWire_P.Gain1_Gain * rtb_GainTheta;
    if (rtb_in_flare > FlyByWire_P.Switch_Threshold) {
      rtb_Switch_c = (FlyByWire_DWork.Delay_DSTATE_a - rtb_GainTheta) * FlyByWire_P.Gain_Gain;
      if (rtb_Switch_c > FlyByWire_P.Saturation_UpperSat) {
        rtb_Switch_c = FlyByWire_P.Saturation_UpperSat;
      } else {
        if (rtb_Switch_c < FlyByWire_P.Saturation_LowerSat) {
          rtb_Switch_c = FlyByWire_P.Saturation_LowerSat;
        }
      }
    } else {
      rtb_Switch_c = FlyByWire_P.Constant_Value_m;
    }

    rtb_Saturation2 = FlyByWire_P.Gain2_Gain * FlyByWire_P.Theta_max1_Value - rtb_Gain1_h;
    if (rtb_Saturation2 > FlyByWire_P.Saturation1_UpperSat) {
      rtb_Saturation2 = FlyByWire_P.Saturation1_UpperSat;
    } else {
      if (rtb_Saturation2 < FlyByWire_P.Saturation1_LowerSat) {
        rtb_Saturation2 = FlyByWire_P.Saturation1_LowerSat;
      }
    }

    if (FlyByWire_DWork.Delay_DSTATE_d <= rtb_Saturation2) {
      rtb_Saturation2 = FlyByWire_P.Gain3_Gain * FlyByWire_P.Theta_max3_Value - rtb_Gain1_h;
      if (rtb_Saturation2 > FlyByWire_P.Saturation2_UpperSat) {
        rtb_Saturation2 = FlyByWire_P.Saturation2_UpperSat;
      } else {
        if (rtb_Saturation2 < FlyByWire_P.Saturation2_LowerSat) {
          rtb_Saturation2 = FlyByWire_P.Saturation2_LowerSat;
        }
      }

      if (FlyByWire_DWork.Delay_DSTATE_d >= rtb_Saturation2) {
        rtb_Saturation2 = FlyByWire_DWork.Delay_DSTATE_d;
      }
    }

    rtb_Saturation2 = look1_binlxpw(rtb_Saturation2, FlyByWire_P.Loaddemand_bp01Data, FlyByWire_P.Loaddemand_tableData,
      2U);
    rtb_Switch_c += rtb_Saturation2;
  }

  rtb_Switch_c += rtb_Divide_ke;
  if (rtb_Switch_c > rtb_nz_limit_up_g) {
    rtb_Switch_c = rtb_nz_limit_up_g;
  } else {
    if (rtb_Switch_c < rtb_nz_limit_lo_g) {
      rtb_Switch_c = rtb_nz_limit_lo_g;
    }
  }

  rtb_Divide_ke = FlyByWire_P.DiscreteDerivativeVariableTs1_Gain * result[1];
  if (FlyByWire_U.in.data.V_tas_kn > FlyByWire_P.Saturation3_UpperSat_p) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation3_UpperSat_p;
  } else if (FlyByWire_U.in.data.V_tas_kn < FlyByWire_P.Saturation3_LowerSat_i) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation3_LowerSat_i;
  } else {
    rtb_Limiterxi1 = FlyByWire_U.in.data.V_tas_kn;
  }

  rtb_LimiteriH = rtb_Limiterxi - (look1_binlxpw(FlyByWire_U.in.data.V_tas_kn, FlyByWire_P.uDLookupTable_bp01Data_j,
    FlyByWire_P.uDLookupTable_tableData_l, 4U) / (FlyByWire_P.Gain5_Gain_g * rtb_Limiterxi1) + FlyByWire_P.Bias_Bias) *
    (rtb_Switch_c - rtb_LimiteriH);
  rtb_Gain1_h = rtb_LimiteriH * look1_binlxpw(FlyByWire_U.in.data.V_tas_kn, FlyByWire_P.DLUT_bp01Data,
    FlyByWire_P.DLUT_tableData, 1U) * FlyByWire_P.DiscreteDerivativeVariableTs_Gain_e;
  rtb_LimiteriH = ((rtb_Divide_ke - FlyByWire_DWork.Delay_DSTATE_fe) / FlyByWire_U.in.time.dt * FlyByWire_P.Gain3_Gain_l
                   + rtb_LimiteriH * look1_binlxpw(FlyByWire_U.in.data.V_tas_kn, FlyByWire_P.PLUT_bp01Data,
    FlyByWire_P.PLUT_tableData, 1U)) + (rtb_Gain1_h - FlyByWire_DWork.Delay_DSTATE_ar) / FlyByWire_U.in.time.dt;
  if (rtb_LimiteriH > FlyByWire_P.Saturation_UpperSat_j) {
    rtb_LimiteriH = FlyByWire_P.Saturation_UpperSat_j;
  } else {
    if (rtb_LimiteriH < FlyByWire_P.Saturation_LowerSat_c) {
      rtb_LimiteriH = FlyByWire_P.Saturation_LowerSat_c;
    }
  }

  FlyByWire_Y.out.pitch.law_normal.nz_c_g = rtb_Switch_c;
  FlyByWire_Y.out.pitch.law_normal.Cstar_g = rtb_Limiterxi;
  FlyByWire_Y.out.pitch.law_normal.eta_dot_deg_s = rtb_LimiteriH;
  FlyByWire_Y.out.pitch.vote.eta_dot_deg_s = rtb_LimiteriH;
  rtb_Switch_c = FlyByWire_P.DiscreteTimeIntegratorVariableTs_Gain_k * rtb_LimiteriH * FlyByWire_U.in.time.dt;
  if ((FlyByWire_DWork.Delay_DSTATE_n == 0.0) || (rtb_BusAssignment_a_sim_data_computed_tracking_mode_on != 0)) {
    FlyByWire_DWork.icLoad_e = 1U;
  }

  if (FlyByWire_DWork.icLoad_e != 0) {
    if (FlyByWire_B.in_flight > FlyByWire_P.Switch_Threshold_d) {
      rtb_Limiterxi1 = rtb_Gainpk4;
    } else {
      rtb_Limiterxi1 = rtb_BusAssignment_c_pitch_data_computed_delta_eta_deg;
    }

    FlyByWire_DWork.Delay_DSTATE_f1 = rtb_Limiterxi1 - rtb_Switch_c;
  }

  rtb_Switch_c += FlyByWire_DWork.Delay_DSTATE_f1;
  if (rtb_Switch_c > FlyByWire_P.DiscreteTimeIntegratorVariableTs_UpperLimit_c) {
    FlyByWire_DWork.Delay_DSTATE_f1 = FlyByWire_P.DiscreteTimeIntegratorVariableTs_UpperLimit_c;
  } else if (rtb_Switch_c < FlyByWire_P.DiscreteTimeIntegratorVariableTs_LowerLimit_b) {
    FlyByWire_DWork.Delay_DSTATE_f1 = FlyByWire_P.DiscreteTimeIntegratorVariableTs_LowerLimit_b;
  } else {
    FlyByWire_DWork.Delay_DSTATE_f1 = rtb_Switch_c;
  }

  if (FlyByWire_DWork.Delay_DSTATE_n > FlyByWire_P.Saturation_UpperSat_jd) {
    rtb_Switch_c = FlyByWire_P.Saturation_UpperSat_jd;
  } else if (FlyByWire_DWork.Delay_DSTATE_n < FlyByWire_P.Saturation_LowerSat_ao) {
    rtb_Switch_c = FlyByWire_P.Saturation_LowerSat_ao;
  } else {
    rtb_Switch_c = FlyByWire_DWork.Delay_DSTATE_n;
  }

  rtb_LimiteriH = FlyByWire_DWork.Delay_DSTATE_f1 * rtb_Switch_c;
  rtb_Saturation2 = FlyByWire_P.Constant_Value_p - rtb_Switch_c;
  if (FlyByWire_DWork.Delay_DSTATE_k > FlyByWire_P.Saturation_UpperSat_c) {
    rtb_Switch_c = FlyByWire_P.Saturation_UpperSat_c;
  } else if (FlyByWire_DWork.Delay_DSTATE_k < FlyByWire_P.Saturation_LowerSat_ci) {
    rtb_Switch_c = FlyByWire_P.Saturation_LowerSat_ci;
  } else {
    rtb_Switch_c = FlyByWire_DWork.Delay_DSTATE_k;
  }

  rtb_Limiterxi = rtb_Gain_ku * rtb_Switch_c;
  rtb_Switch_c = FlyByWire_P.Constant_Value_k - rtb_Switch_c;
  rtb_Switch_c *= rtb_BusAssignment_c_pitch_data_computed_delta_eta_deg;
  rtb_BusAssignment_m_pitch_output_eta_deg = (rtb_Limiterxi + rtb_Switch_c) * rtb_Saturation2 + rtb_LimiteriH;
  if (rtb_eta_trim_deg_should_freeze == FlyByWire_P.CompareToConstant_const_h) {
    rtb_LimiteriH = FlyByWire_P.Constant_Value;
  } else {
    rtb_LimiteriH = FlyByWire_DWork.Delay_DSTATE_f1;
  }

  rtb_Switch_c = FlyByWire_P.Gain_Gain_ip * rtb_LimiteriH * FlyByWire_P.DiscreteTimeIntegratorVariableTs_Gain_g *
    FlyByWire_U.in.time.dt;
  if (rtb_NOT2) {
    FlyByWire_DWork.icLoad_b = 1U;
  }

  if (FlyByWire_DWork.icLoad_b != 0) {
    FlyByWire_DWork.Delay_DSTATE_mx = rtb_eta_trim_deg_reset_deg - rtb_Switch_c;
  }

  rtb_Switch_c += FlyByWire_DWork.Delay_DSTATE_mx;
  if (rtb_Switch_c > FlyByWire_P.DiscreteTimeIntegratorVariableTs_UpperLimit_j) {
    FlyByWire_DWork.Delay_DSTATE_mx = FlyByWire_P.DiscreteTimeIntegratorVariableTs_UpperLimit_j;
  } else if (rtb_Switch_c < FlyByWire_P.DiscreteTimeIntegratorVariableTs_LowerLimit_g) {
    FlyByWire_DWork.Delay_DSTATE_mx = FlyByWire_P.DiscreteTimeIntegratorVariableTs_LowerLimit_g;
  } else {
    FlyByWire_DWork.Delay_DSTATE_mx = rtb_Switch_c;
  }

  rtb_Limiterxi1 = FlyByWire_DWork.Delay_DSTATE_mx - FlyByWire_DWork.Delay_DSTATE_m0;
  u1 = rtb_eta_trim_deg_rate_limit_up_deg_s * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * rtb_eta_trim_deg_rate_limit_lo_deg_s;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_m0 += rtb_Limiterxi1;
  rtb_LimiteriH = look1_binlxpw(FlyByWire_U.in.data.V_tas_kn, FlyByWire_P.uDLookupTable_bp01Data_f,
    FlyByWire_P.uDLookupTable_tableData_f, 3U);
  rtb_Gain1_l = FlyByWire_P.Gain1_Gain_jh * rtb_BusAssignment_a_sim_input_delta_zeta_pos;
  if (rtb_Gain1_l > rtb_LimiteriH) {
    rtb_Gain1_l = rtb_LimiteriH;
  } else {
    rtb_LimiteriH *= FlyByWire_P.Gain2_Gain_n;
    if (rtb_Gain1_l < rtb_LimiteriH) {
      rtb_Gain1_l = rtb_LimiteriH;
    }
  }

  if (FlyByWire_DWork.is_active_c5_FlyByWire == 0U) {
    FlyByWire_DWork.is_active_c5_FlyByWire = 1U;
    FlyByWire_DWork.is_c5_FlyByWire = FlyByWire_IN_GroundMode;
    rtb_in_flight = 0;
  } else if (FlyByWire_DWork.is_c5_FlyByWire == FlyByWire_IN_FlightMode) {
    if (rtb_on_ground == 1) {
      FlyByWire_DWork.is_c5_FlyByWire = FlyByWire_IN_GroundMode;
      rtb_in_flight = 0;
    } else {
      rtb_in_flight = 1;
    }
  } else {
    if (((rtb_on_ground == 0) && (rtb_GainTheta > 8.0)) || (FlyByWire_U.in.data.H_radio_ft > 400.0)) {
      FlyByWire_DWork.is_c5_FlyByWire = FlyByWire_IN_FlightMode;
      rtb_in_flight = 1;
    } else {
      rtb_in_flight = 0;
    }
  }

  if (rtb_in_flight > FlyByWire_P.Saturation_UpperSat_p) {
    rtb_LimiteriH = FlyByWire_P.Saturation_UpperSat_p;
  } else if (rtb_in_flight < FlyByWire_P.Saturation_LowerSat_h) {
    rtb_LimiteriH = FlyByWire_P.Saturation_LowerSat_h;
  } else {
    rtb_LimiteriH = rtb_in_flight;
  }

  rtb_Limiterxi1 = rtb_LimiteriH - FlyByWire_DWork.Delay_DSTATE_g;
  u1 = FlyByWire_P.RateLimiterVariableTs_up_k * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs_lo_fs;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_g += rtb_Limiterxi1;
  rtb_Saturation2 = FlyByWire_U.in.data.engine_1_thrust_lbf - FlyByWire_U.in.data.engine_2_thrust_lbf;
  rtb_Limiterxi = FlyByWire_U.in.time.dt * FlyByWire_P.LagFilter_C1_l;
  rtb_Limiterxi1 = rtb_Limiterxi + FlyByWire_P.Constant_Value_ft;
  FlyByWire_DWork.Delay1_DSTATE_i = 1.0 / rtb_Limiterxi1 * (FlyByWire_P.Constant_Value_ft - rtb_Limiterxi) *
    FlyByWire_DWork.Delay1_DSTATE_i + (rtb_Saturation2 + FlyByWire_DWork.Delay_DSTATE_o) * (rtb_Limiterxi /
    rtb_Limiterxi1);
  rtb_Product_a = FlyByWire_DWork.Delay1_DSTATE_i * look1_binlxpw(FlyByWire_U.in.data.V_tas_kn,
    FlyByWire_P.ScheduledGain_BreakpointsForDimension1, FlyByWire_P.ScheduledGain_Table, 3U);
  rtb_BusAssignment_p_roll_data_computed_delta_xi_deg = FlyByWire_P.Gain_Gain_c * Phi;
  rtb_Limiterxi1 = FlyByWire_P.Gain1_Gain_m * Phi + look1_binlxpw(rtb_GainPhi, FlyByWire_P.BankAngleProtection_bp01Data,
    FlyByWire_P.BankAngleProtection_tableData, 6U);
  if (rtb_Limiterxi1 > FlyByWire_P.Saturation_UpperSat_n) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation_UpperSat_n;
  } else {
    if (rtb_Limiterxi1 < FlyByWire_P.Saturation_LowerSat_o) {
      rtb_Limiterxi1 = FlyByWire_P.Saturation_LowerSat_o;
    }
  }

  rtb_Switch_c = rtb_Limiterxi1 * FlyByWire_DWork.Delay_DSTATE_g;
  rtb_LimiteriH = FlyByWire_P.DiscreteTimeIntegratorVariableTs_Gain_d * rtb_Switch_c * FlyByWire_U.in.time.dt;
  if ((FlyByWire_DWork.Delay_DSTATE_g == 0.0) || (rtb_BusAssignment_a_sim_data_computed_tracking_mode_on != 0) ||
      (FlyByWire_U.in.data.autopilot_custom_on != 0.0)) {
    FlyByWire_DWork.icLoad_m = 1U;
  }

  if (FlyByWire_DWork.icLoad_m != 0) {
    FlyByWire_DWork.Delay_DSTATE_h = rtb_GainPhi - rtb_LimiteriH;
  }

  rtb_LimiteriH += FlyByWire_DWork.Delay_DSTATE_h;
  if (rtb_LimiteriH > FlyByWire_P.DiscreteTimeIntegratorVariableTs_UpperLimit_d) {
    FlyByWire_DWork.Delay_DSTATE_h = FlyByWire_P.DiscreteTimeIntegratorVariableTs_UpperLimit_d;
  } else if (rtb_LimiteriH < FlyByWire_P.DiscreteTimeIntegratorVariableTs_LowerLimit_k) {
    FlyByWire_DWork.Delay_DSTATE_h = FlyByWire_P.DiscreteTimeIntegratorVariableTs_LowerLimit_k;
  } else {
    FlyByWire_DWork.Delay_DSTATE_h = rtb_LimiteriH;
  }

  if (FlyByWire_U.in.data.autopilot_custom_on > FlyByWire_P.Switch_Threshold_p) {
    if (rtb_BusAssignment_a_sim_data_computed_tracking_mode_on > FlyByWire_P.Switch1_Threshold) {
      rtb_Limiterxi1 = rtb_GainPhi;
    } else {
      rtb_Limiterxi1 = FlyByWire_U.in.data.autopilot_custom_Phi_c_deg;
    }
  } else {
    rtb_Limiterxi1 = FlyByWire_DWork.Delay_DSTATE_h;
  }

  rtb_LimiteriH = rtb_Limiterxi1 - FlyByWire_DWork.Delay_DSTATE_d1;
  u1 = FlyByWire_P.RateLimiterVariableTs2_up * FlyByWire_U.in.time.dt;
  if (rtb_LimiteriH >= u1) {
    rtb_LimiteriH = u1;
  }

  u1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs2_lo;
  if (rtb_LimiteriH > u1) {
    u1 = rtb_LimiteriH;
  }

  FlyByWire_DWork.Delay_DSTATE_d1 += u1;
  rtb_Limiterxi1 = rtb_Gain1_l - FlyByWire_DWork.Delay_DSTATE_c;
  u1 = FlyByWire_P.RateLimiterVariableTs_up_m * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs_lo_p;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_c += rtb_Limiterxi1;
  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.LagFilter_C1_d;
  rtb_LimiteriH = rtb_Limiterxi1 + FlyByWire_P.Constant_Value_b;
  FlyByWire_DWork.Delay1_DSTATE_h = 1.0 / rtb_LimiteriH * (FlyByWire_P.Constant_Value_b - rtb_Limiterxi1) *
    FlyByWire_DWork.Delay1_DSTATE_h + (rtb_Gain + FlyByWire_DWork.Delay_DSTATE_n2) * (rtb_Limiterxi1 / rtb_LimiteriH);
  rtb_LimiteriH = FlyByWire_U.in.time.dt * FlyByWire_P.WashoutFilter_C1;
  rtb_Limiterxi = rtb_LimiteriH + FlyByWire_P.Constant_Value_mn;
  rtb_Product3 = FlyByWire_P.Constant_Value_mn / rtb_Limiterxi;
  rtb_Limiterxi1 = FlyByWire_DWork.Delay_DSTATE_h5 * rtb_Product3;
  rtb_Product3 *= rtb_Gain;
  FlyByWire_DWork.Delay1_DSTATE_c = 1.0 / rtb_Limiterxi * (FlyByWire_P.Constant_Value_mn - rtb_LimiteriH) *
    FlyByWire_DWork.Delay1_DSTATE_c + (rtb_Product3 - rtb_Limiterxi1);
  FlyByWire_Y.out.roll.law_normal.pk_c_deg_s = rtb_Switch_c;
  rtb_BusAssignment_e_roll_law_normal_xi_deg = ((FlyByWire_P.Gain3_Gain_k * FlyByWire_DWork.Delay_DSTATE_c +
    FlyByWire_DWork.Delay_DSTATE_d1) - rtb_GainPhi) * FlyByWire_P.Gain2_Gain_i + FlyByWire_P.Gain1_Gain_mg * result[0] *
    FlyByWire_P.pKp_Gain;
  rtb_Limiterxi1 = static_cast<real_T>(rtb_on_ground) - FlyByWire_DWork.Delay_DSTATE_b;
  u1 = FlyByWire_P.RateLimiterVariableTs_up_dl * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs_lo_fw;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_b += rtb_Limiterxi1;
  if (FlyByWire_DWork.Delay_DSTATE_b > FlyByWire_P.Saturation_UpperSat_ep) {
    rtb_Switch_c = FlyByWire_P.Saturation_UpperSat_ep;
  } else if (FlyByWire_DWork.Delay_DSTATE_b < FlyByWire_P.Saturation_LowerSat_n) {
    rtb_Switch_c = FlyByWire_P.Saturation_LowerSat_n;
  } else {
    rtb_Switch_c = FlyByWire_DWork.Delay_DSTATE_b;
  }

  rtb_LimiteriH = FlyByWire_U.in.data.autopilot_custom_Beta_c_deg * rtb_Switch_c;
  rtb_Sum1_g0 = FlyByWire_P.Constant_Value_gk - rtb_Switch_c;
  rtb_Limiterxi = FlyByWire_U.in.time.dt * FlyByWire_P.LagFilter_C1_c;
  rtb_Limiterxi1 = rtb_Limiterxi + FlyByWire_P.Constant_Value_e;
  FlyByWire_DWork.Delay1_DSTATE_e = 1.0 / rtb_Limiterxi1 * (FlyByWire_P.Constant_Value_e - rtb_Limiterxi) *
    FlyByWire_DWork.Delay1_DSTATE_e + (FlyByWire_U.in.data.beta_deg + FlyByWire_DWork.Delay_DSTATE_ow) * (rtb_Limiterxi /
    rtb_Limiterxi1);
  rtb_Product3 = FlyByWire_U.in.data.autopilot_custom_Beta_c_deg + rtb_Product_a;
  rtb_Switch_c = FlyByWire_U.in.time.dt * FlyByWire_P.LagFilter1_C1;
  rtb_Limiterxi = rtb_Switch_c + FlyByWire_P.Constant_Value_o;
  FlyByWire_DWork.Delay1_DSTATE_n = 1.0 / rtb_Limiterxi * (FlyByWire_P.Constant_Value_o - rtb_Switch_c) *
    FlyByWire_DWork.Delay1_DSTATE_n + (rtb_Product3 + FlyByWire_DWork.Delay_DSTATE_ay) * (rtb_Switch_c / rtb_Limiterxi);
  rtb_AND = ((rtb_BusAssignment_a_sim_data_computed_tracking_mode_on == 0) && (FlyByWire_U.in.data.autopilot_custom_on
              != 0.0));
  if (rtb_AND) {
    rtb_Switch_c = FlyByWire_DWork.Delay1_DSTATE_n;
  } else {
    rtb_Switch_c = FlyByWire_DWork.Delay1_DSTATE_e;
  }

  rtb_Switch_c -= FlyByWire_DWork.Delay1_DSTATE_e;
  rtb_Limiterxi = FlyByWire_P.Gain4_Gain_o * rtb_Switch_c;
  rtb_Switch_c = FlyByWire_P.Gain7_Gain * rtb_Switch_c * FlyByWire_P.DiscreteTimeIntegratorVariableTs1_Gain *
    FlyByWire_U.in.time.dt;
  if (!rtb_AND) {
    FlyByWire_DWork.icLoad_i = 1U;
  }

  if (FlyByWire_DWork.icLoad_i != 0) {
    FlyByWire_DWork.Delay_DSTATE_gt = FlyByWire_P.fbw_output_MATLABStruct.roll.output.zeta_deg - rtb_Switch_c;
  }

  rtb_Switch_c += FlyByWire_DWork.Delay_DSTATE_gt;
  if (rtb_Switch_c > FlyByWire_P.DiscreteTimeIntegratorVariableTs1_UpperLimit) {
    FlyByWire_DWork.Delay_DSTATE_gt = FlyByWire_P.DiscreteTimeIntegratorVariableTs1_UpperLimit;
  } else if (rtb_Switch_c < FlyByWire_P.DiscreteTimeIntegratorVariableTs1_LowerLimit) {
    FlyByWire_DWork.Delay_DSTATE_gt = FlyByWire_P.DiscreteTimeIntegratorVariableTs1_LowerLimit;
  } else {
    FlyByWire_DWork.Delay_DSTATE_gt = rtb_Switch_c;
  }

  rtb_Limiterxi1 = (rtb_Limiterxi + FlyByWire_DWork.Delay_DSTATE_gt) - FlyByWire_DWork.Delay_DSTATE_ok;
  u1 = FlyByWire_P.RateLimiterVariableTs1_up_p * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterVariableTs1_lo_hd;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_ok += rtb_Limiterxi1;
  if (FlyByWire_U.in.data.autopilot_custom_on > FlyByWire_P.Saturation_UpperSat_o) {
    rtb_Switch_c = FlyByWire_P.Saturation_UpperSat_o;
  } else if (FlyByWire_U.in.data.autopilot_custom_on < FlyByWire_P.Saturation_LowerSat_ee) {
    rtb_Switch_c = FlyByWire_P.Saturation_LowerSat_ee;
  } else {
    rtb_Switch_c = FlyByWire_U.in.data.autopilot_custom_on;
  }

  if (FlyByWire_U.in.data.V_tas_kn > FlyByWire_P.Saturation_UpperSat_l) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation_UpperSat_l;
  } else if (FlyByWire_U.in.data.V_tas_kn < FlyByWire_P.Saturation_LowerSat_l) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation_LowerSat_l;
  } else {
    rtb_Limiterxi1 = FlyByWire_U.in.data.V_tas_kn;
  }

  rtb_Limiterxi1 = (FlyByWire_DWork.Delay1_DSTATE_h - std::sin(FlyByWire_P.Gain1_Gain_br *
    FlyByWire_DWork.Delay_DSTATE_d1) * FlyByWire_P.Constant2_Value_l * std::cos(FlyByWire_P.Gain1_Gain_c * rtb_GainTheta)
                    / (FlyByWire_P.Gain6_Gain_j * rtb_Limiterxi1) * FlyByWire_P.Gain_Gain_cd) * FlyByWire_P.Gain_Gain_hk;
  rtb_Limiterxi = FlyByWire_P.Gain6_Gain_k * FlyByWire_DWork.Delay1_DSTATE_c;
  if (rtb_Limiterxi1 > FlyByWire_P.Saturation1_UpperSat_h) {
    rtb_Limiterxi1 = FlyByWire_P.Saturation1_UpperSat_h;
  } else {
    if (rtb_Limiterxi1 < FlyByWire_P.Saturation1_LowerSat_g) {
      rtb_Limiterxi1 = FlyByWire_P.Saturation1_LowerSat_g;
    }
  }

  if (rtb_Limiterxi > FlyByWire_P.Saturation2_UpperSat_e) {
    rtb_Limiterxi = FlyByWire_P.Saturation2_UpperSat_e;
  } else {
    if (rtb_Limiterxi < FlyByWire_P.Saturation2_LowerSat_gp) {
      rtb_Limiterxi = FlyByWire_P.Saturation2_LowerSat_gp;
    }
  }

  rtb_Switch_c = ((rtb_Sum1_g0 * FlyByWire_DWork.Delay_DSTATE_ok + rtb_LimiteriH) * rtb_Switch_c +
                  (FlyByWire_P.Constant_Value_oz - rtb_Switch_c) * FlyByWire_P.Constant3_Value) +
    ((FlyByWire_DWork.Delay_DSTATE_c + rtb_Limiterxi1) * FlyByWire_DWork.Delay_DSTATE_g + rtb_Limiterxi);
  if (FlyByWire_U.in.data.H_radio_ft <= FlyByWire_P.CompareToConstant_const) {
    rtb_Limiterxi1 = FlyByWire_P.Constant2_Value;
  } else {
    rtb_Limiterxi1 = rtb_Switch_c;
  }

  rtb_LimiteriH = FlyByWire_P.Gain4_Gain_h * rtb_Limiterxi1 * FlyByWire_P.DiscreteTimeIntegratorVariableTs1_Gain_e *
    FlyByWire_U.in.time.dt;
  if ((FlyByWire_U.in.data.autopilot_custom_on == 0.0) || (rtb_BusAssignment_a_sim_data_computed_tracking_mode_on != 0))
  {
    FlyByWire_DWork.icLoad_c = 1U;
  }

  if (FlyByWire_DWork.icLoad_c != 0) {
    FlyByWire_DWork.Delay_DSTATE_fzn = result_tmp - rtb_LimiteriH;
  }

  rtb_LimiteriH += FlyByWire_DWork.Delay_DSTATE_fzn;
  if (rtb_LimiteriH > FlyByWire_P.DiscreteTimeIntegratorVariableTs1_UpperLimit_e) {
    FlyByWire_DWork.Delay_DSTATE_fzn = FlyByWire_P.DiscreteTimeIntegratorVariableTs1_UpperLimit_e;
  } else if (rtb_LimiteriH < FlyByWire_P.DiscreteTimeIntegratorVariableTs1_LowerLimit_o) {
    FlyByWire_DWork.Delay_DSTATE_fzn = FlyByWire_P.DiscreteTimeIntegratorVariableTs1_LowerLimit_o;
  } else {
    FlyByWire_DWork.Delay_DSTATE_fzn = rtb_LimiteriH;
  }

  rtb_Limiterxi1 = FlyByWire_DWork.Delay_DSTATE_fzn - FlyByWire_DWork.Delay_DSTATE_md;
  u1 = FlyByWire_P.Constant_Value_ba * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.Constant1_Value_a;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_md += rtb_Limiterxi1;
  rtb_Sum1_g0 = rtb_Switch_c;
  rtb_Limiterxi = FlyByWire_DWork.Delay_DSTATE_g + FlyByWire_U.in.data.autopilot_custom_on;
  if (rtb_Limiterxi > FlyByWire_P.Saturation1_UpperSat_e) {
    rtb_Switch_c = FlyByWire_P.Saturation1_UpperSat_e;
  } else if (rtb_Limiterxi < FlyByWire_P.Saturation1_LowerSat_l) {
    rtb_Switch_c = FlyByWire_P.Saturation1_LowerSat_l;
  } else {
    rtb_Switch_c = rtb_Limiterxi;
  }

  if (rtb_Switch_c > FlyByWire_P.Saturation_UpperSat_d0) {
    rtb_Switch_c = FlyByWire_P.Saturation_UpperSat_d0;
  } else {
    if (rtb_Switch_c < FlyByWire_P.Saturation_LowerSat_oa) {
      rtb_Switch_c = FlyByWire_P.Saturation_LowerSat_oa;
    }
  }

  rtb_LimiteriH = rtb_BusAssignment_e_roll_law_normal_xi_deg * rtb_Switch_c;
  rtb_Switch_c = FlyByWire_P.Constant_Value_mh - rtb_Switch_c;
  rtb_Switch_c *= rtb_BusAssignment_p_roll_data_computed_delta_xi_deg;
  rtb_LimiteriH += rtb_Switch_c;
  if (rtb_Limiterxi > FlyByWire_P.Saturation_UpperSat_eq) {
    rtb_Limiterxi = FlyByWire_P.Saturation_UpperSat_eq;
  } else {
    if (rtb_Limiterxi < FlyByWire_P.Saturation_LowerSat_nm) {
      rtb_Limiterxi = FlyByWire_P.Saturation_LowerSat_nm;
    }
  }

  if (rtb_Limiterxi > FlyByWire_P.Saturation_UpperSat_erp) {
    rtb_Switch_c = FlyByWire_P.Saturation_UpperSat_erp;
  } else if (rtb_Limiterxi < FlyByWire_P.Saturation_LowerSat_lj) {
    rtb_Switch_c = FlyByWire_P.Saturation_LowerSat_lj;
  } else {
    rtb_Switch_c = rtb_Limiterxi;
  }

  rtb_Limiterxi = rtb_Sum1_g0 * rtb_Switch_c;
  rtb_Switch_c = FlyByWire_P.Constant_Value_e2 - rtb_Switch_c;
  rtb_Switch_c *= rtb_Gain1_l;
  rtb_Limiterxi += rtb_Switch_c;
  rtb_Limiterxi1 = rtb_BusAssignment_m_pitch_output_eta_deg - FlyByWire_DWork.Delay_DSTATE_ow5;
  u1 = FlyByWire_P.RateLimitereta_up * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimitereta_lo;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_ow5 += rtb_Limiterxi1;
  rtb_Limiterxi1 = rtb_LimiteriH - FlyByWire_DWork.Delay_DSTATE_kya;
  u1 = FlyByWire_P.RateLimiterxi_up * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterxi_lo;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_kya += rtb_Limiterxi1;
  rtb_Limiterxi1 = rtb_Limiterxi - FlyByWire_DWork.Delay_DSTATE_k2;
  u1 = FlyByWire_P.RateLimiterzeta_up * FlyByWire_U.in.time.dt;
  if (rtb_Limiterxi1 < u1) {
    u1 = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_U.in.time.dt * FlyByWire_P.RateLimiterzeta_lo;
  if (u1 > rtb_Limiterxi1) {
    rtb_Limiterxi1 = u1;
  }

  FlyByWire_DWork.Delay_DSTATE_k2 += rtb_Limiterxi1;
  FlyByWire_Y.out.sim.time.dt = FlyByWire_U.in.time.dt;
  FlyByWire_Y.out.sim.time.simulation_time = FlyByWire_U.in.time.simulation_time;
  FlyByWire_Y.out.sim.time.monotonic_time = FlyByWire_DWork.Delay_DSTATE;
  FlyByWire_Y.out.sim.data.nz_g = FlyByWire_U.in.data.nz_g;
  FlyByWire_Y.out.sim.data.Theta_deg = rtb_GainTheta;
  FlyByWire_Y.out.sim.data.Phi_deg = rtb_GainPhi;
  FlyByWire_Y.out.sim.data.q_deg_s = rtb_Gainqk;
  FlyByWire_Y.out.sim.data.r_deg_s = rtb_Gain;
  FlyByWire_Y.out.sim.data.p_deg_s = rtb_Gainpk;
  FlyByWire_Y.out.sim.data.qk_deg_s = result[1];
  FlyByWire_Y.out.sim.data.rk_deg_s = result[2];
  FlyByWire_Y.out.sim.data.pk_deg_s = result[0];
  FlyByWire_Y.out.sim.data.qk_dot_deg_s2 = result_0[1];
  FlyByWire_Y.out.sim.data.rk_dot_deg_s2 = result_0[2];
  FlyByWire_Y.out.sim.data.pk_dot_deg_s2 = result_0[0];
  FlyByWire_Y.out.sim.data.psi_magnetic_deg = FlyByWire_U.in.data.psi_magnetic_deg;
  FlyByWire_Y.out.sim.data.psi_true_deg = FlyByWire_U.in.data.psi_true_deg;
  FlyByWire_Y.out.sim.data.eta_deg = rtb_Gainpk4;
  FlyByWire_Y.out.sim.data.xi_deg = FlyByWire_P.Gainpk5_Gain * FlyByWire_U.in.data.xi_pos;
  FlyByWire_Y.out.sim.data.zeta_deg = FlyByWire_P.Gainpk6_Gain * FlyByWire_U.in.data.zeta_pos;
  FlyByWire_Y.out.sim.data.zeta_trim_deg = result_tmp;
  FlyByWire_Y.out.sim.data.alpha_deg = FlyByWire_U.in.data.alpha_deg;
  FlyByWire_Y.out.sim.data.beta_deg = FlyByWire_U.in.data.beta_deg;
  FlyByWire_Y.out.sim.data.beta_dot_deg_s = FlyByWire_U.in.data.beta_dot_deg_s;
  FlyByWire_Y.out.sim.data.V_ias_kn = FlyByWire_U.in.data.V_ias_kn;
  FlyByWire_Y.out.sim.data.V_tas_kn = FlyByWire_U.in.data.V_tas_kn;
  FlyByWire_Y.out.sim.data.V_mach = FlyByWire_U.in.data.V_mach;
  FlyByWire_Y.out.sim.data.H_ft = FlyByWire_U.in.data.H_ft;
  FlyByWire_Y.out.sim.data.H_ind_ft = FlyByWire_U.in.data.H_ind_ft;
  FlyByWire_Y.out.sim.data.H_radio_ft = FlyByWire_U.in.data.H_radio_ft;
  FlyByWire_Y.out.sim.data.CG_percent_MAC = FlyByWire_U.in.data.CG_percent_MAC;
  FlyByWire_Y.out.sim.data.total_weight_kg = FlyByWire_U.in.data.total_weight_kg;
  rtb_Limiterxi1 = FlyByWire_P.Gain_Gain_i * FlyByWire_U.in.data.gear_animation_pos_0 - FlyByWire_P.Constant_Value_g;
  if (rtb_Limiterxi1 > FlyByWire_P.Saturation_UpperSat_e) {
    FlyByWire_Y.out.sim.data.gear_strut_compression_0 = FlyByWire_P.Saturation_UpperSat_e;
  } else if (rtb_Limiterxi1 < FlyByWire_P.Saturation_LowerSat_e) {
    FlyByWire_Y.out.sim.data.gear_strut_compression_0 = FlyByWire_P.Saturation_LowerSat_e;
  } else {
    FlyByWire_Y.out.sim.data.gear_strut_compression_0 = rtb_Limiterxi1;
  }

  FlyByWire_Y.out.sim.data.flaps_handle_index = FlyByWire_U.in.data.flaps_handle_index;
  FlyByWire_Y.out.sim.data.spoilers_left_pos = FlyByWire_U.in.data.spoilers_left_pos;
  FlyByWire_Y.out.sim.data.spoilers_right_pos = FlyByWire_U.in.data.spoilers_right_pos;
  FlyByWire_Y.out.sim.data.autopilot_master_on = FlyByWire_U.in.data.autopilot_master_on;
  FlyByWire_Y.out.sim.data.slew_on = FlyByWire_U.in.data.slew_on;
  FlyByWire_Y.out.sim.data.pause_on = FlyByWire_U.in.data.pause_on;
  FlyByWire_Y.out.sim.data.tracking_mode_on_override = FlyByWire_U.in.data.tracking_mode_on_override;
  FlyByWire_Y.out.sim.data.autopilot_custom_on = FlyByWire_U.in.data.autopilot_custom_on;
  FlyByWire_Y.out.sim.data.autopilot_custom_Theta_c_deg = FlyByWire_U.in.data.autopilot_custom_Theta_c_deg;
  FlyByWire_Y.out.sim.data.autopilot_custom_Phi_c_deg = FlyByWire_U.in.data.autopilot_custom_Phi_c_deg;
  FlyByWire_Y.out.sim.data.autopilot_custom_Beta_c_deg = FlyByWire_U.in.data.autopilot_custom_Beta_c_deg;
  FlyByWire_Y.out.sim.data.simulation_rate = FlyByWire_U.in.data.simulation_rate;
  FlyByWire_Y.out.sim.data.ice_structure_percent = FlyByWire_U.in.data.ice_structure_percent;
  FlyByWire_Y.out.sim.data.linear_cl_alpha_per_deg = FlyByWire_U.in.data.linear_cl_alpha_per_deg;
  FlyByWire_Y.out.sim.data.alpha_stall_deg = FlyByWire_U.in.data.alpha_stall_deg;
  FlyByWire_Y.out.sim.data.alpha_zero_lift_deg = FlyByWire_U.in.data.alpha_zero_lift_deg;
  FlyByWire_Y.out.sim.data.ambient_density_kg_per_m3 = FlyByWire_U.in.data.ambient_density_kg_per_m3;
  FlyByWire_Y.out.sim.data.ambient_pressure_mbar = FlyByWire_U.in.data.ambient_pressure_mbar;
  FlyByWire_Y.out.sim.data.ambient_temperature_celsius = FlyByWire_U.in.data.ambient_temperature_celsius;
  FlyByWire_Y.out.sim.data.ambient_wind_x_kn = FlyByWire_U.in.data.ambient_wind_x_kn;
  FlyByWire_Y.out.sim.data.ambient_wind_y_kn = FlyByWire_U.in.data.ambient_wind_y_kn;
  FlyByWire_Y.out.sim.data.ambient_wind_z_kn = FlyByWire_U.in.data.ambient_wind_z_kn;
  FlyByWire_Y.out.sim.data.ambient_wind_velocity_kn = FlyByWire_U.in.data.ambient_wind_velocity_kn;
  FlyByWire_Y.out.sim.data.ambient_wind_direction_deg = FlyByWire_U.in.data.ambient_wind_direction_deg;
  FlyByWire_Y.out.sim.data.total_air_temperature_celsius = FlyByWire_U.in.data.total_air_temperature_celsius;
  FlyByWire_Y.out.sim.data.latitude_deg = FlyByWire_U.in.data.latitude_deg;
  FlyByWire_Y.out.sim.data.longitude_deg = FlyByWire_U.in.data.longitude_deg;
  FlyByWire_Y.out.sim.data.engine_1_thrust_lbf = FlyByWire_U.in.data.engine_1_thrust_lbf;
  FlyByWire_Y.out.sim.data.engine_2_thrust_lbf = FlyByWire_U.in.data.engine_2_thrust_lbf;
  FlyByWire_Y.out.sim.data.thrust_lever_1_pos = FlyByWire_U.in.data.thrust_lever_1_pos;
  FlyByWire_Y.out.sim.data.thrust_lever_2_pos = FlyByWire_U.in.data.thrust_lever_2_pos;
  FlyByWire_Y.out.sim.data_computed.on_ground = rtb_on_ground;
  FlyByWire_Y.out.sim.data_computed.tracking_mode_on = rtb_BusAssignment_a_sim_data_computed_tracking_mode_on;
  FlyByWire_Y.out.sim.input.delta_eta_pos = Theta;
  FlyByWire_Y.out.sim.input.delta_xi_pos = Phi;
  FlyByWire_Y.out.sim.input.delta_zeta_pos = rtb_BusAssignment_a_sim_input_delta_zeta_pos;
  FlyByWire_Y.out.pitch.data_computed.delta_eta_deg = rtb_BusAssignment_c_pitch_data_computed_delta_eta_deg;
  FlyByWire_Y.out.pitch.data_computed.in_flight = FlyByWire_B.in_flight;
  FlyByWire_Y.out.pitch.data_computed.in_rotation = rtb_in_rotation;
  FlyByWire_Y.out.pitch.data_computed.in_flare = rtb_in_flare;
  FlyByWire_Y.out.pitch.data_computed.in_flight_gain = FlyByWire_DWork.Delay_DSTATE_n;
  FlyByWire_Y.out.pitch.data_computed.in_rotation_gain = FlyByWire_DWork.Delay_DSTATE_k;
  FlyByWire_Y.out.pitch.data_computed.nz_limit_up_g = rtb_nz_limit_up_g;
  FlyByWire_Y.out.pitch.data_computed.nz_limit_lo_g = rtb_nz_limit_lo_g;
  FlyByWire_Y.out.pitch.data_computed.eta_trim_deg_should_freeze = rtb_eta_trim_deg_should_freeze;
  FlyByWire_Y.out.pitch.data_computed.eta_trim_deg_reset = rtb_NOT2;
  FlyByWire_Y.out.pitch.data_computed.eta_trim_deg_reset_deg = rtb_eta_trim_deg_reset_deg;
  FlyByWire_Y.out.pitch.data_computed.eta_trim_deg_should_write = rtb_eta_trim_deg_should_write;
  FlyByWire_Y.out.pitch.data_computed.eta_trim_deg_rate_limit_up_deg_s = rtb_eta_trim_deg_rate_limit_up_deg_s;
  FlyByWire_Y.out.pitch.data_computed.eta_trim_deg_rate_limit_lo_deg_s = rtb_eta_trim_deg_rate_limit_lo_deg_s;
  FlyByWire_Y.out.pitch.data_computed.flare_Theta_deg = FlyByWire_DWork.Delay1_DSTATE;
  FlyByWire_Y.out.pitch.data_computed.flare_Theta_c_deg = FlyByWire_DWork.Delay_DSTATE_a;
  FlyByWire_Y.out.pitch.data_computed.flare_Theta_c_rate_deg_s = FlyByWire_B.flare_Theta_c_rate_deg_s;
  FlyByWire_Y.out.pitch.law_rotation.eta_deg = rtb_Gain_ku;
  FlyByWire_Y.out.pitch.integrated.eta_deg = FlyByWire_DWork.Delay_DSTATE_f1;
  FlyByWire_Y.out.pitch.output.eta_deg = rtb_BusAssignment_m_pitch_output_eta_deg;
  FlyByWire_Y.out.pitch.output.eta_trim_deg = FlyByWire_DWork.Delay_DSTATE_m0;
  FlyByWire_Y.out.roll.data_computed.delta_xi_deg = rtb_BusAssignment_p_roll_data_computed_delta_xi_deg;
  FlyByWire_Y.out.roll.data_computed.delta_zeta_deg = rtb_Gain1_l;
  FlyByWire_Y.out.roll.data_computed.in_flight = rtb_in_flight;
  FlyByWire_Y.out.roll.data_computed.in_flight_gain = FlyByWire_DWork.Delay_DSTATE_g;
  FlyByWire_Y.out.roll.data_computed.zeta_trim_deg_should_write = (FlyByWire_U.in.data.autopilot_custom_on != 0.0);
  FlyByWire_Y.out.roll.data_computed.beta_target_deg = rtb_Product_a;
  FlyByWire_Y.out.roll.law_normal.Phi_c_deg = FlyByWire_DWork.Delay_DSTATE_d1;
  FlyByWire_Y.out.roll.law_normal.xi_deg = rtb_BusAssignment_e_roll_law_normal_xi_deg;
  FlyByWire_Y.out.roll.law_normal.zeta_deg = rtb_Sum1_g0;
  FlyByWire_Y.out.roll.output.xi_deg = rtb_LimiteriH;
  FlyByWire_Y.out.roll.output.zeta_deg = rtb_Limiterxi;
  FlyByWire_Y.out.roll.output.zeta_trim_deg = FlyByWire_DWork.Delay_DSTATE_md;
  rtb_Limiterxi1 = FlyByWire_P.Gaineta_Gain_d * FlyByWire_DWork.Delay_DSTATE_ow5;
  if (rtb_Limiterxi1 > FlyByWire_P.Limitereta_UpperSat) {
    FlyByWire_Y.out.output.eta_pos = FlyByWire_P.Limitereta_UpperSat;
  } else if (rtb_Limiterxi1 < FlyByWire_P.Limitereta_LowerSat) {
    FlyByWire_Y.out.output.eta_pos = FlyByWire_P.Limitereta_LowerSat;
  } else {
    FlyByWire_Y.out.output.eta_pos = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_P.GainiH_Gain * FlyByWire_DWork.Delay_DSTATE_m0;
  if (rtb_Limiterxi1 > FlyByWire_P.LimiteriH_UpperSat) {
    FlyByWire_Y.out.output.eta_trim_deg = FlyByWire_P.LimiteriH_UpperSat;
  } else if (rtb_Limiterxi1 < FlyByWire_P.LimiteriH_LowerSat) {
    FlyByWire_Y.out.output.eta_trim_deg = FlyByWire_P.LimiteriH_LowerSat;
  } else {
    FlyByWire_Y.out.output.eta_trim_deg = rtb_Limiterxi1;
  }

  FlyByWire_Y.out.output.eta_trim_deg_should_write = rtb_eta_trim_deg_should_write;
  rtb_Limiterxi1 = FlyByWire_P.Gainxi_Gain_n * FlyByWire_DWork.Delay_DSTATE_kya;
  if (rtb_Limiterxi1 > FlyByWire_P.Limiterxi_UpperSat) {
    FlyByWire_Y.out.output.xi_pos = FlyByWire_P.Limiterxi_UpperSat;
  } else if (rtb_Limiterxi1 < FlyByWire_P.Limiterxi_LowerSat) {
    FlyByWire_Y.out.output.xi_pos = FlyByWire_P.Limiterxi_LowerSat;
  } else {
    FlyByWire_Y.out.output.xi_pos = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_P.Gainxi1_Gain_e * FlyByWire_DWork.Delay_DSTATE_k2;
  if (rtb_Limiterxi1 > FlyByWire_P.Limiterxi1_UpperSat) {
    FlyByWire_Y.out.output.zeta_pos = FlyByWire_P.Limiterxi1_UpperSat;
  } else if (rtb_Limiterxi1 < FlyByWire_P.Limiterxi1_LowerSat) {
    FlyByWire_Y.out.output.zeta_pos = FlyByWire_P.Limiterxi1_LowerSat;
  } else {
    FlyByWire_Y.out.output.zeta_pos = rtb_Limiterxi1;
  }

  rtb_Limiterxi1 = FlyByWire_P.Gainxi2_Gain * FlyByWire_DWork.Delay_DSTATE_md;
  if (rtb_Limiterxi1 > FlyByWire_P.Limiterxi2_UpperSat) {
    FlyByWire_Y.out.output.zeta_trim_pos = FlyByWire_P.Limiterxi2_UpperSat;
  } else if (rtb_Limiterxi1 < FlyByWire_P.Limiterxi2_LowerSat) {
    FlyByWire_Y.out.output.zeta_trim_pos = FlyByWire_P.Limiterxi2_LowerSat;
  } else {
    FlyByWire_Y.out.output.zeta_trim_pos = rtb_Limiterxi1;
  }

  FlyByWire_Y.out.output.zeta_trim_pos_should_write = (FlyByWire_U.in.data.autopilot_custom_on != 0.0);
  FlyByWire_DWork.Delay_DSTATE_j = rtb_GainTheta;
  FlyByWire_DWork.Delay_DSTATE_ky = rtb_ManualSwitch;
  FlyByWire_DWork.Delay_DSTATE_fv = rtb_Gain_d;
  FlyByWire_DWork.Delay_DSTATE_fz = rtb_Sum2;
  FlyByWire_DWork.icLoad = 0U;
  FlyByWire_DWork.Delay_DSTATE_fe = rtb_Divide_ke;
  FlyByWire_DWork.Delay_DSTATE_ar = rtb_Gain1_h;
  FlyByWire_DWork.icLoad_e = 0U;
  FlyByWire_DWork.icLoad_b = 0U;
  FlyByWire_DWork.Delay_DSTATE_o = rtb_Saturation2;
  FlyByWire_DWork.icLoad_m = 0U;
  FlyByWire_DWork.Delay_DSTATE_n2 = rtb_Gain;
  FlyByWire_DWork.Delay_DSTATE_h5 = rtb_Gain;
  FlyByWire_DWork.Delay_DSTATE_ow = FlyByWire_U.in.data.beta_deg;
  FlyByWire_DWork.Delay_DSTATE_ay = rtb_Product3;
  FlyByWire_DWork.icLoad_i = 0U;
  FlyByWire_DWork.icLoad_c = 0U;
}

void FlyByWireModelClass::initialize()
{
  (void) std::memset((static_cast<void *>(&FlyByWire_B)), 0,
                     sizeof(BlockIO_FlyByWire_T));
  (void) std::memset(static_cast<void *>(&FlyByWire_DWork), 0,
                     sizeof(D_Work_FlyByWire_T));
  FlyByWire_U.in = FlyByWire_rtZfbw_input;
  FlyByWire_Y.out = FlyByWire_rtZfbw_output;
  FlyByWire_DWork.Delay_DSTATE = FlyByWire_P.Delay_InitialCondition;
  FlyByWire_DWork.Delay_DSTATE_n = FlyByWire_P.RateLimiterVariableTs_InitialCondition;
  FlyByWire_DWork.Delay_DSTATE_j = FlyByWire_P.Delay_InitialCondition_f;
  FlyByWire_DWork.Delay1_DSTATE = FlyByWire_P.Delay1_InitialCondition;
  FlyByWire_DWork.Delay_DSTATE_k = FlyByWire_P.RateLimiterVariableTs1_InitialCondition;
  FlyByWire_DWork.Delay_DSTATE_a = FlyByWire_P.RateLimiterDynamicVariableTs_InitialCondition;
  FlyByWire_DWork.Delay_DSTATE_f = FlyByWire_P.RateLimiterVariableTs_InitialCondition_n;
  FlyByWire_DWork.Delay_DSTATE_ky = FlyByWire_P.DiscreteDerivativeVariableTs_InitialCondition;
  FlyByWire_DWork.Delay_DSTATE_fv = FlyByWire_P.DiscreteDerivativeVariableTs_InitialCondition_k;
  FlyByWire_DWork.Delay_DSTATE_fz = FlyByWire_P.Delay_InitialCondition_e;
  FlyByWire_DWork.Delay1_DSTATE_p = FlyByWire_P.Delay1_InitialCondition_b;
  FlyByWire_DWork.icLoad = 1U;
  FlyByWire_DWork.Delay_DSTATE_m = FlyByWire_P.RateLimiterVariableTs1_InitialCondition_h;
  FlyByWire_DWork.Delay_DSTATE_d = FlyByWire_P.RateLimiterVariableTs_InitialCondition_c;
  FlyByWire_DWork.Delay_DSTATE_fe = FlyByWire_P.DiscreteDerivativeVariableTs1_InitialCondition;
  FlyByWire_DWork.Delay_DSTATE_ar = FlyByWire_P.DiscreteDerivativeVariableTs_InitialCondition_c;
  FlyByWire_DWork.icLoad_e = 1U;
  FlyByWire_DWork.icLoad_b = 1U;
  FlyByWire_DWork.Delay_DSTATE_m0 = FlyByWire_P.RateLimiterDynamicVariableTs_InitialCondition_i;
  FlyByWire_DWork.Delay_DSTATE_g = FlyByWire_P.RateLimiterVariableTs_InitialCondition_f;
  FlyByWire_DWork.Delay_DSTATE_o = FlyByWire_P.Delay_InitialCondition_fd;
  FlyByWire_DWork.Delay1_DSTATE_i = FlyByWire_P.Delay1_InitialCondition_p;
  FlyByWire_DWork.Delay_DSTATE_d1 = FlyByWire_P.RateLimiterVariableTs2_InitialCondition;
  FlyByWire_DWork.icLoad_m = 1U;
  FlyByWire_DWork.Delay_DSTATE_c = FlyByWire_P.RateLimiterVariableTs_InitialCondition_fc;
  FlyByWire_DWork.Delay_DSTATE_n2 = FlyByWire_P.Delay_InitialCondition_l;
  FlyByWire_DWork.Delay1_DSTATE_h = FlyByWire_P.Delay1_InitialCondition_m;
  FlyByWire_DWork.Delay_DSTATE_h5 = FlyByWire_P.Delay_InitialCondition_p;
  FlyByWire_DWork.Delay1_DSTATE_c = FlyByWire_P.Delay1_InitialCondition_e;
  FlyByWire_DWork.Delay_DSTATE_b = FlyByWire_P.RateLimiterVariableTs_InitialCondition_p;
  FlyByWire_DWork.Delay_DSTATE_ok = FlyByWire_P.RateLimiterVariableTs1_InitialCondition_f;
  FlyByWire_DWork.Delay_DSTATE_ow = FlyByWire_P.Delay_InitialCondition_ej;
  FlyByWire_DWork.Delay1_DSTATE_e = FlyByWire_P.Delay1_InitialCondition_mq;
  FlyByWire_DWork.Delay_DSTATE_ay = FlyByWire_P.Delay_InitialCondition_i;
  FlyByWire_DWork.Delay1_DSTATE_n = FlyByWire_P.Delay1_InitialCondition_k;
  FlyByWire_DWork.icLoad_i = 1U;
  FlyByWire_DWork.Delay_DSTATE_md = FlyByWire_P.RateLimiterDynamicVariableTs_InitialCondition_i4;
  FlyByWire_DWork.icLoad_c = 1U;
  FlyByWire_DWork.Delay_DSTATE_ow5 = FlyByWire_P.RateLimitereta_InitialCondition;
  FlyByWire_DWork.Delay_DSTATE_kya = FlyByWire_P.RateLimiterxi_InitialCondition;
  FlyByWire_DWork.Delay_DSTATE_k2 = FlyByWire_P.RateLimiterzeta_InitialCondition;
  FlyByWire_DWork.is_active_c1_FlyByWire = 0U;
  FlyByWire_DWork.is_c1_FlyByWire = FlyByWire_IN_NO_ACTIVE_CHILD;
  FlyByWire_DWork.is_active_c3_FlyByWire = 0U;
  FlyByWire_DWork.is_c3_FlyByWire = FlyByWire_IN_NO_ACTIVE_CHILD;
  FlyByWire_DWork.is_active_c6_FlyByWire = 0U;
  FlyByWire_DWork.is_c6_FlyByWire = FlyByWire_IN_NO_ACTIVE_CHILD;
  FlyByWire_DWork.is_active_c2_FlyByWire = 0U;
  FlyByWire_DWork.is_c2_FlyByWire = FlyByWire_IN_NO_ACTIVE_CHILD;
  FlyByWire_DWork.is_active_c7_FlyByWire = 0U;
  FlyByWire_DWork.is_c7_FlyByWire = FlyByWire_IN_NO_ACTIVE_CHILD;
  FlyByWire_DWork.is_active_c9_FlyByWire = 0U;
  FlyByWire_DWork.is_c9_FlyByWire = FlyByWire_IN_NO_ACTIVE_CHILD;
  FlyByWire_DWork.is_active_c8_FlyByWire = 0U;
  FlyByWire_DWork.is_c8_FlyByWire = FlyByWire_IN_NO_ACTIVE_CHILD;
  FlyByWire_DWork.is_active_c5_FlyByWire = 0U;
  FlyByWire_DWork.is_c5_FlyByWire = FlyByWire_IN_NO_ACTIVE_CHILD;
}

void FlyByWireModelClass::terminate()
{
}

FlyByWireModelClass::FlyByWireModelClass()
{
}

FlyByWireModelClass::~FlyByWireModelClass()
{
}
