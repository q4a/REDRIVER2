#ifndef PAD_H
#define PAD_H

#define PADBUFFER_SIZE 34

enum ECameraPad
{
	CAMERA_PAD_LOOK_LEFT		= 0x1,
	CAMERA_PAD_LOOK_RIGHT		= 0x2,

	CAMERA_PAD_LOOK_BACK		= CAMERA_PAD_LOOK_LEFT | CAMERA_PAD_LOOK_RIGHT,
	CAMERA_PAD_LOOK_BACK_DED	= 0x200
};

enum ETannerPad
{
	TANNER_PAD_ACTION		= 0x10,
	TANNER_PAD_POWER		= 0x20,
	TANNER_PAD_GOFORWARD	= 0x40 | 0x1000,
	TANNER_PAD_GOBACK		= 0x80 | 0x4000,
	TANNER_PAD_TURNLEFT		= 0x8000,
	TANNER_PAD_TURNRIGHT	= 0x2000,

	TANNER_PAD_ACTION_DED	= 0x400,		// R3 mapped for car entrance
};

enum ECarPads
{
	CAR_PAD_FASTSTEER		= 0x4,
	CAR_PAD_HANDBRAKE		= 0x10,
	CAR_PAD_WHEELSPIN		= 0x20,
	CAR_PAD_ACCEL			= 0x40,
	CAR_PAD_BRAKE			= 0x80,
	CAR_PAD_UP				= 0x1000,
	CAR_PAD_LEFT			= 0x8000,
	CAR_PAD_RIGHT			= 0x2000,

	CAR_PAD_LEAVECAR_DED	= 0x400,		// R3 mapped

	CAR_PAD_LEAVECAR		= (CAR_PAD_UP | CAR_PAD_HANDBRAKE),	// fixme: combinations?
};

extern int pad_connected;
extern int numPadsConnected;
extern int gVibration;

extern PAD Pads[2];

extern char padbuffer[2][PADBUFFER_SIZE];
extern DUPLICATION DuplicatePadData;

extern void InitControllers(); // 0x0006B480
extern void CloseControllers(); // 0x0006BDF8

extern void ReadControllers(); // 0x0006B5A8

extern void SetPadVibration(int pad, unsigned char type); // 0x0006BE38
extern void StopPadVibration(int pad); // 0x0006BEB4

extern void HandleDualShock(); // 0x0006B8E0
extern void StopDualShockMotors(); // 0x0006BEEC

extern void SetDuplicatePadData(char *buffer, int size); // 0x0006BEF4

#endif
