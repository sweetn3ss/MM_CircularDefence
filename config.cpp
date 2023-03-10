class CfgPatches
{
	class 82nd_Yeeter {
		name="82ndSOC Yeeter";
		requiredAddons[]= {
			"OPTRE_Weapons",
			"OPTRE_FC_Weapons"
		};
		units[]={};
		weapons[]={};
		magazines[]={};
		ammo[]={};
		requiredVersion=0.1;
	};
};
class Extended_PostInit_EventHandlers {
    class MesaYeeter_Key {
        init = "spawn esThrow_fnc_MesaYeeter_Key";
    };
};
class cfgFunctions {
	class esThrow {
		class functions {
			file="82nd_Yeeter\functions";
			class bubbleshield_throw {};
		};
		class Keys {
			file="\82nd_Yeeter\functions";
			class MesaYeeter_Key {};
		};
	};
};
class cfgAmmo {
	class ACE_SatchelCharge_Remote_Ammo_Thrown;
	class 82nd_Bubbleshield_Ammo: ACE_SatchelCharge_Remote_Ammo_Thrown {
		hit=0;
		indirectHit=0;
		indirectHitRange=0;
		defaultMagazine="82nd_Bubble_Mag";
		model="\82nd_Yeeter\data\bubble\bubbleprojectile.p3d";
		explosive=0;
		explosionType="";
		mineModelDisabled="\82nd_Yeeter\data\bubble\bubbleprojectile.p3d";
		triggerWhenDestroyed=0;
		explosionEffects="";
		CraterEffects="";
		soundHit1[]={"",0,0,0};
		multiSoundHit[]={};
		mineInconspicuousness=9999;
		timetolive=15;
		explosionTime=6;
		effectFlare="";
		effectsFire="";
		effectsMissile="";
		effectsSmoke="";
		explosionEffectsDir="";
		explosionForceCoef="";
		explosionPos="";
		explosionEffectsRadius=0;
		explosionSoundEffect="";
		SoundSetExplosion[] ={""};
		class CamShakeExplode {
			power=0;
			duration=0;
			frequency=0;
			distance=0;
		};
	};
};
class cfgMagazines {
	class OPTRE_M9_Frag;
	class 82nd_Bubble_Mag : OPTRE_M9_Frag {
		scope=2;
		scopeArsenal=2;
		displayName="[82ndSOC] Z-4190 TPE/SS";
		displayNameShort="Throwable Bubble Shield";
		descriptionShort="Throwable Bubble Shield";
		type="256";
		allowedSlots[]={901,701};
		ammo="82nd_Bubbleshield_Ammo";
		model="OPTRE_Weapons\explosives\m2_smk_grenade.p3d";
		mass=15;
		count=1;
		sound[]={"A3\sounds_f\dummysound",0.000316228,1,10};
		initSpeed=12;
	};
};
class cfgWeapons {
	class Grenadelauncher;
	class ThrowMuzzle;
	class Throw: Grenadelauncher {
		muzzles[]+= {
			"82nd_Bubble_Muzzle",
		};
        class 82nd_Bubble_Muzzle: ThrowMuzzle {
			reloadtime=0;
			magazines[]={"82nd_Bubble_Mag"};
			
			class EventHandlers {
				fired="_this call Throw_fnc_bubbleshield_throw;";
			};
		};
	};
};

class cfgVehicles {
	class ThingX;
	class Items_base_F: ThingX {
		class DestructionEffects;
	};
	class House;
	class House_F: House {
		class DestructionEffects;
	};
	class 82nd_Bubble_Shield: House_F {
		scope=2;
		scopeCurator=2;
		armor=999999;
		armorStructural=999;
		displayName="[82ndSOC] Bubble Shield";
		model="\82nd_Yeeter\data\bubble\bubbledeployed.p3d";
		author="Saint";
		editorCategory="82nd_Battalion";
		editorSubcategory="82nd_Props";
		class EventHandlers {
			Dammaged = "_this call Throw_fnc_bubbleshield_hit;";
		};
	};
};