#pragma once
#include <cstdint>

//======================================================================
// CONFIGURATION KEYS FOR u-blox X20P
//======================================================================
//
// Each constant below represents a u-blox configuration item (Key ID)
// that can be set or read using UBX-CFG-VALSET / UBX-CFG-VALGET messages.
//
// Organized by configuration groups for UART, message output,
// time mode, RTCM, and high-precision navigation.
//
//======================================================================

//======================================================================
// UART1 CONFIGURATION KEYS
//======================================================================

// CFG-UART1 : Basic UART1 port setup
const uint32_t CFG_UART1_BAUDRATE          = 0x40520001;   // Baud rate for UART1 (e.g. 115200)
const uint32_t CFG_UART1_STOPBITS          = 0x20520002;   // Number of stop bits (1 or 2)
const uint32_t CFG_UART1_DATABITS          = 0x20520003;   // Number of data bits (usually 8)
const uint32_t CFG_UART1_PARITY            = 0x20520004;   // Parity mode (0=None, 1=Odd, 2=Even)
const uint32_t CFG_UART1_ENABLED           = 0x10520005;   // Enable/disable UART1 (1=enabled, 0=disabled)

// CFG-UART1INPROT : Input protocols on UART1
const uint32_t CFG_UART1INPROT_UBX         = 0x10730001;   // Enable UBX input on UART1
const uint32_t CFG_UART1INPROT_NMEA        = 0x10730002;   // Enable NMEA input on UART1
const uint32_t CFG_UART1INPROT_RTCM3X      = 0x10730004;   // Enable RTCM3 input (for corrections)
const uint32_t CFG_UART1INPROT_SPARTN      = 0x10730005;   // Enable SPARTN input (for PPP-RTK data)

// CFG-UART1OUTPROT : Output protocols on UART1
const uint32_t CFG_UART1OUTPROT_UBX        = 0x10740001;   // Enable UBX output (binary navigation)
const uint32_t CFG_UART1OUTPROT_NMEA       = 0x10740002;   // Enable NMEA output (ASCII sentences)
const uint32_t CFG_UART1OUTPROT_SPARTN     = 0x10740004;   // Enable SPARTN output (rare)

//======================================================================
// MESSAGE OUTPUT KEYS (CFG-MSGOUT-*)
//======================================================================
//
// These determine which messages the module outputs over UART1.
// 0 = Disabled, 1 = Enabled.
//
//======================================================================

//CFG-MSGOUT-NMEA
const uint32_t CFG_MSGOUT_NMEA_ID_DTM_UART1          = 0x209100A7;   // Datum reference
const uint32_t CFG_MSGOUT_NMEA_ID_GBS_UART1          = 0x209100DE;   // GNSS satellite fault detection
const uint32_t CFG_MSGOUT_NMEA_ID_GGA_UART1          = 0x209100BB;   // Fix data (time, position, altitude)
const uint32_t CFG_MSGOUT_NMEA_ID_GLL_UART1          = 0x209100B7;   // Latitude/longitude data
const uint32_t CFG_MSGOUT_NMEA_ID_GNS_UART1          = 0x209100B6;   // GNSS fix data (multi-constellation)
const uint32_t CFG_MSGOUT_NMEA_ID_GRS_UART1          = 0x209100CF;   // GNSS range residuals
const uint32_t CFG_MSGOUT_NMEA_ID_GSA_UART1          = 0x209100C1;   // DOP and active satellites
const uint32_t CFG_MSGOUT_NMEA_ID_GST_UART1          = 0x209100D4;   // Pseudorange error statistics
const uint32_t CFG_MSGOUT_NMEA_ID_GSV_UART1          = 0x209100C5;   // Satellites in view
const uint32_t CFG_MSGOUT_NMEA_ID_RLM_UART1          = 0x20910402;   // Return link message (SBAS)
const uint32_t CFG_MSGOUT_NMEA_ID_RMC_UART1          = 0x209100AC;   // Recommended minimum GNSS data
const uint32_t CFG_MSGOUT_NMEA_ID_VLW_UART1          = 0x209100E8;   // Distance traveled (water speed)
const uint32_t CFG_MSGOUT_NMEA_ID_VTG_UART1          = 0x209100B1;   // Course over ground and ground speed
const uint32_t CFG_MSGOUT_NMEA_ID_ZDA_UART1          = 0x209100DC;   // Date and time

//CFG-MSGOUT-RTCM3
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1005_UART1     = 0x209102BE;   // Stationary RTK reference station position
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1074_UART1     = 0x2091035F;   // GPS MSM4 (pseudorange, carrier, Doppler)
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1077_UART1     = 0x209102CD;   // GPS MSM7 (high-precision)
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1084_UART1     = 0x20910364;   // GLONASS MSM4
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1087_UART1     = 0x209102D1;   // GLONASS MSM7
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1094_UART1     = 0x20910369;   // Galileo MSM4
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1097_UART1     = 0x20910319;   // Galileo MSM7
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1124_UART1     = 0x2091036D;   // BeiDou MSM4
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1127_UART1     = 0x209102D7;   // BeiDou MSM7
const uint32_t CFG_MSGOUT_RTCM_3X_TYPE1230_UART1     = 0x20910304;   // GLONASS bias information

//CFG-MSGOUT-LOG
const uint32_t CFG_MSGOUT_UBX_LOG_INFO_UART1         = 0x2091025A;   // Logging information output

//CFG-MSGOUT-MON
const uint32_t CFG_MSGOUT_UBX_MON_COMMS_UART1        = 0x20910350;   // Communication port status
const uint32_t CFG_MSGOUT_UBX_MON_HW3_UART1          = 0x20910355;   // Hardware status (HW3)
const uint32_t CFG_MSGOUT_UBX_MON_RF_UART1           = 0x2091035A;   // RF signal monitoring
const uint32_t CFG_MSGOUT_UBX_MON_RXR_UART1          = 0x20910188;   // Receiver monitoring
const uint32_t CFG_MSGOUT_UBX_MON_SPAN_UART1         = 0x2091038C;   // Spectrum analysis (interference)
const uint32_t CFG_MSGOUT_UBX_MON_SYS_UART1          = 0x2091069E;   // System status information

//CFG-MSGOUT-NAV
const uint32_t CFG_MSGOUT_UBX_NAV_CLOCK_UART1        = 0x20910066;   // Clock information
const uint32_t CFG_MSGOUT_UBX_NAV_COV_UART1          = 0x20910084;   // Position covariance
const uint32_t CFG_MSGOUT_UBX_NAV_DOP_UART1          = 0x20910039;   // Dilution of precision values
const uint32_t CFG_MSGOUT_UBX_NAV_EOE_UART1          = 0x20910160;   // End of epoch marker
const uint32_t CFG_MSGOUT_UBX_NAV_GEOFENCE_UART1     = 0x209100A2;   // Geofencing status
const uint32_t CFG_MSGOUT_UBX_NAV_HPPOSLLH_UART1     = 0x20910032;   // High-precision lat/lon/height
const uint32_t CFG_MSGOUT_UBX_NAV_HPPOSCEF_UART1     = 0x20910028;   // High-precision ECEF position
const uint32_t CFG_MSGOUT_UBX_NAV_ODO_UART1          = 0x2091008A;   // Odometer solution
const uint32_t CFG_MSGOUT_UBX_NAV_ORB_UART1          = 0x20910111;   // Satellite orbit parameters
const uint32_t CFG_MSGOUT_UBX_NAV_POSECEF_UART1      = 0x20910025;   // Position in ECEF coordinates
const uint32_t CFG_MSGOUT_UBX_NAV_POSLLH_UART1       = 0x20910021;   // Position in lat/lon/height
const uint32_t CFG_MSGOUT_UBX_NAV_PVT_UART1          = 0x20910007;   // Navigation solution (position, velocity, time)
const uint32_t CFG_MSGOUT_UBX_NAV_RELPOSNED_UART1    = 0x20910091;   // Relative position (for RTK)
const uint32_t CFG_MSGOUT_UBX_NAV_SAT_UART1          = 0x20910015;   // Satellite information
const uint32_t CFG_MSGOUT_UBX_NAV_SBAS_UART1         = 0x2091006B;   // SBAS status
const uint32_t CFG_MSGOUT_UBX_NAV_SIG_UART1          = 0x20910344;   // Signal quality information
const uint32_t CFG_MSGOUT_UBX_NAV_STATUS_UART1       = 0x20910008;   // Receiver navigation status
const uint32_t CFG_MSGOUT_UBX_NAV_SVIN_UART1         = 0x2091008E;   // Survey-in status (base station)
const uint32_t CFG_MSGOUT_UBX_NAV_TIMEBDS_UART1      = 0x20910507;   // BeiDou time solution
const uint32_t CFG_MSGOUT_UBX_NAV_TIMEGAL_UART1      = 0x20910557;   // Galileo time solution
const uint32_t CFG_MSGOUT_UBX_NAV_TIMEGLO_UART1      = 0x20910587;   // GLONASS time solution
const uint32_t CFG_MSGOUT_UBX_NAV_TIMEGPS_UART1      = 0x20910407;   // GPS time solution
const uint32_t CFG_MSGOUT_UBX_NAV_TIMELS_UART1       = 0x20910564;   // Leap second information
const uint32_t CFG_MSGOUT_UBX_NAV_TIMEUTC_UART1      = 0x209105C;    // UTC time solution
const uint32_t CFG_MSGOUT_UBX_NAV_VELECEF_UART1      = 0x20910041;   // Velocity in ECEF coordinates
const uint32_t CFG_MSGOUT_UBX_NAV_VELNED_UART1       = 0x20910043;   // Velocity in NED coordinates
const uint32_t CFG_MSGOUT_UBX_NAV_TIMEQZSS_UART1     = 0x20910387;   // QZSS time solution
const uint32_t CFG_MSGOUT_UBX_NAV_TIMETRUSTED_UART1  = 0x209103A9;   // Trusted time solution

//======================================================================
// TIME MODE (TMODE) CONFIGURATION KEYS
//======================================================================
//
// Used when the receiver operates as an RTK base station.
// Enables Fixed or Survey-In modes, and sets ARP coordinates.
//
//======================================================================

const uint32_t CFG_TMODE_MODE               = 0x40030001;   // Receiver mode (0=disabled, 1=survey-in, 2=fixed)
const uint32_t CFG_TMODE_POS_TYPE           = 0x40030002;   // Position type (0=ECEF, 1=LLH)
const uint32_t CFG_TMODE_ECEF_X             = 0x40030003;   // ARP position ECEF X [cm]
const uint32_t CFG_TMODE_ECEF_Y             = 0x40030004;   // ARP position ECEF Y [cm]
const uint32_t CFG_TMODE_ECEF_Z             = 0x40030005;   // ARP position ECEF Z [cm]
const uint32_t CFG_TMODE_ECEF_X_HP          = 0x20030006;   // High-precision ECEF X [0.1 mm]
const uint32_t CFG_TMODE_ECEF_Y_HP          = 0x20030007;   // High-precision ECEF Y [0.1 mm]
const uint32_t CFG_TMODE_ECEF_Z_HP          = 0x20030008;   // High-precision ECEF Z [0.1 mm]
const uint32_t CFG_TMODE_LAT                = 0x40030009;   // Latitude (LLH) [deg * 1e-7]
const uint32_t CFG_TMODE_LON                = 0x4003000A;   // Longitude (LLH) [deg * 1e-7]
const uint32_t CFG_TMODE_HEIGHT             = 0x4003000B;   // Height (LLH) [cm]
const uint32_t CFG_TMODE_LAT_HP             = 0x2003000C;   // High-precision latitude [deg * 1e-9]
const uint32_t CFG_TMODE_LON_HP             = 0x2003000D;   // High-precision longitude [deg * 1e-9]
const uint32_t CFG_TMODE_HEIGHT_HP          = 0x2003000E;   // High-precision height [mm]
const uint32_t CFG_TMODE_FIXED_POS_ACC      = 0x4003000F;   // Fixed position 3D accuracy [mm]
const uint32_t CFG_TMODE_SVIN_MIN_DUR       = 0x40030010;   // Minimum survey-in duration [s]
const uint32_t CFG_TMODE_SVIN_ACC_LIMIT     = 0x40030011;   // Survey-in accuracy limit [mm]

//======================================================================
// RTCM CONFIGURATION KEYS
//======================================================================

const uint32_t CFG_RTCM_DF003_OUT           = 0x30090001;   // Reference station ID output value (0–4095)
const uint32_t CFG_RTCM_DF003_IN            = 0x30090008;   // Reference station ID input value (0–4095)
const uint32_t CFG_RTCM_DF003_IN_FILTER     = 0x20090009;   // RTCM input filter mode (0=disabled, 1=relaxed, 2=strict)

//======================================================================
// HIGH PRECISION NAVIGATION CONFIGURATION (NAVHPG)
//======================================================================

const uint32_t CFG_NAVHPG_DGNSSMODE         = 0x20140011;   // Differential correction mode (2=FLOAT, 3=FIXED, 5=CAR)
