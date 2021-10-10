//fn_keyPressed
private ["_key","_shift","_ctrl","_alt"];
if (dialog) exitWith {false};

_key = _this select 1;
_shift = _this select 2;
_ctrl = _this select 3;
_alt = _this select 4;

if (not (_key == 60 && _shift && !_ctrl && !_alt)) exitWith {false};
//hint "Key workin'";

closeDialog 0;
[] spawn TFSC_fnc_adminCheck;
true

