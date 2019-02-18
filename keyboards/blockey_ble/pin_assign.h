#ifndef KEYBOARDS_BLOCKEY_BLE_REV1_PIN_ASSIGN_H_
#define KEYBOARDS_BLOCKEY_BLE_REV1_PIN_ASSIGN_H_

#undef B0
#undef B1
#undef B2
#undef B3
#undef B4
#undef B5
#undef B6
#undef C6
#undef D0
#undef D1
#undef D2
#undef D3
#undef D4
#undef D7
#undef E6
#undef F4
#undef F5
#undef F6
#undef F7

#define D3 PIN1
#define D2 PIN2
#define D1 PIN5
#define D0 PIN6
#define D4 PIN7
#define C6 PIN8
#define D7 PIN9
#define E6 PIN10
#define B4 PIN11
#define B5 PIN12
#define B6 PIN13
#define B2 PIN14
#define B3 PIN15
#define B1 PIN16
#define F7 PIN17
#define F6 PIN18
#define F5 PIN19
#define F4 PIN20

#define MATRIX_ROW_PINS { D3, D1, D4, E6, B5, D2, F6, B3, B2, B6 }
#define MATRIX_COL_PINS { D0, B4, C6, D7, F4, F5, F7 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL, or CUSTOM_MATRIX */
#define DIODE_DIRECTION COL2ROW

#endif /* KEYBOARDS_BLOCKEY_BLE_REV1_PIN_ASSIGN_H_ */
