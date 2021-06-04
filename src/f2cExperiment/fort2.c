/* fort2.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct bcdptr_1_ {
    integer bcdptr[7];
};

#define bcdptr_1 (*(struct bcdptr_1_ *) &bcdptr_)

struct numptr_1_ {
    integer numptr[13];
};

#define numptr_1 (*(struct numptr_1_ *) &numptr_)

struct sublst_1_ {
    integer sublst[136];
};

#define sublst_1 (*(struct sublst_1_ *) &sublst_)

struct nametb_1_ {
    integer charst, charnd, inamst, inamnd, namest, nammax, ifixst, ifixnd, 
	    numbst, numbnd, namtbl[3000];
};

#define nametb_1 (*(struct nametb_1_ *) &nametb_)

struct cnamtb_1_ {
    char cnamtb[18000], cnumtb[36000];
};

#define cnamtb_1 (*(struct cnamtb_1_ *) &cnamtb_)

/* Initialized data */

struct {
    integer e_1[7];
    } bcdptr_ = { 166, 724, 1092, 1410, 167, 168, 169 };

struct {
    integer e_1[13];
    } numptr_ = { 3001, 3011, 3002, 3012, 3003, 3004, 3005, 3006, 3007, 3008, 
	    3009, 3010, 3013 };

struct {
    integer e_1[92];
    integer fill_2[2];
    integer e_3[10];
    integer fill_4[16];
    integer e_5[15];
    integer fill_6[1];
    } sublst_ = { 59, 62, 63, 65, 68, 67, 69, 73, 74, 76, 77, 100, 80, 81, 82,
	     89, 78, 79, 91, 92, 89, 93, 94, 95, 96, 97, 154, 99, 101, 102, 
	    103, 104, 105, 106, 107, 108, 109, 110, 112, 113, 116, 117, 118, 
	    2541, 155, 61, 64, 66, 58, 70, 71, 72, 75, 83, 84, 85, 86, 87, 88,
	     90, 66, 98, 114, 115, 60, 90, 128, 132, 111, 68, 111, 127, 133, 
	    57, 138, 139, 141, 142, 143, 144, 145, 148, 146, 147, 157, 158, 
	    159, 160, 161, 162, 163, 164, {0}, 149, 150, 151, 152, 153, 129, 
	    154, 155, 156, 165, {0}, 124, 125, 122, 121, 123, 126, 134, 135, 
	    140, 136, 137, 637, 1029, 1629, 2598 };

struct {
    integer e_1[179];
    integer fill_2[3];
    integer e_3;
    integer fill_4[2];
    integer e_5[2];
    integer fill_6[6];
    integer e_7;
    integer fill_8[23];
    integer e_9[2];
    integer fill_10[2];
    integer e_11;
    integer fill_12[14];
    integer e_13;
    integer fill_14[10];
    integer e_15;
    integer fill_16[7];
    integer e_17;
    integer fill_18[1];
    integer e_19;
    integer fill_20[8];
    integer e_21;
    integer fill_22[12];
    integer e_23;
    integer fill_24[3];
    integer e_25;
    integer fill_26[1];
    integer e_27;
    integer fill_28[4];
    integer e_29;
    integer fill_30[12];
    integer e_31[2];
    integer fill_32[8];
    integer e_33;
    integer fill_34[6];
    integer e_35[2];
    integer fill_36[6];
    integer e_37[2];
    integer fill_38[6];
    integer e_39[2];
    integer fill_40[5];
    integer e_41;
    integer fill_42[1];
    integer e_43;
    integer fill_44[5];
    integer e_45[3];
    integer fill_46[1];
    integer e_47[3];
    integer fill_48[6];
    integer e_49;
    integer fill_50[2];
    integer e_51;
    integer fill_52[6];
    integer e_53;
    integer fill_54[22];
    integer e_55;
    integer fill_56[14];
    integer e_57;
    integer fill_58[6];
    integer e_59;
    integer fill_60[9];
    integer e_61;
    integer fill_62[3];
    integer e_63;
    integer fill_64[1];
    integer e_65[10];
    integer fill_66[2];
    integer e_67[3];
    integer fill_68[2];
    integer e_69;
    integer fill_70[8];
    integer e_71;
    integer fill_72[2];
    integer e_73[2];
    integer fill_74[1];
    integer e_75;
    integer fill_76[16];
    integer e_77[2];
    integer fill_78[11];
    integer e_79;
    integer fill_80[3];
    integer e_81;
    integer fill_82[1];
    integer e_83;
    integer fill_84[2];
    integer e_85;
    integer fill_86[2];
    integer e_87;
    integer fill_88[3];
    integer e_89[2];
    integer fill_90[2];
    integer e_91[2];
    integer fill_92[1];
    integer e_93[3];
    integer fill_94[2];
    integer e_95;
    integer fill_96[4];
    integer e_97;
    integer fill_98[1];
    integer e_99;
    integer fill_100[1];
    integer e_101;
    integer fill_102[4];
    integer e_103[2];
    integer fill_104[2];
    integer e_105;
    integer fill_106[5];
    integer e_107;
    integer fill_108[5];
    integer e_109[5];
    integer fill_110[5];
    integer e_111;
    integer fill_112[8];
    integer e_113;
    integer fill_114[2];
    integer e_115;
    integer fill_116[1];
    integer e_117;
    integer fill_118[1];
    integer e_119[3];
    integer fill_120[3];
    integer e_121;
    integer fill_122[4];
    integer e_123;
    integer fill_124[4];
    integer e_125;
    integer fill_126[16];
    integer e_127[2];
    integer fill_128[8];
    integer e_129;
    integer fill_130[4];
    integer e_131[3];
    integer fill_132[9];
    integer e_133;
    integer fill_134[4];
    integer e_135;
    integer fill_136[1];
    integer e_137;
    integer fill_138[1];
    integer e_139;
    integer fill_140[12];
    integer e_141[2];
    integer fill_142[19];
    integer e_143[2];
    integer fill_144[3];
    integer e_145[2];
    integer fill_146[1];
    integer e_147[5];
    integer fill_148[14];
    integer e_149;
    integer fill_150[11];
    integer e_151;
    integer fill_152[9];
    integer e_153;
    integer fill_154[26];
    integer e_155;
    integer fill_156[5];
    integer e_157;
    integer fill_158[2];
    integer e_159;
    integer fill_160[3];
    integer e_161;
    integer fill_162[1];
    integer e_163;
    integer fill_164[3];
    integer e_165;
    integer fill_166[1];
    integer e_167[2];
    integer fill_168[16];
    integer e_169;
    integer fill_170[3];
    integer e_171;
    integer fill_172[8];
    integer e_173;
    integer fill_174[3];
    integer e_175[2];
    integer fill_176[7];
    integer e_177[4];
    integer fill_178[6];
    integer e_179;
    integer fill_180[1];
    integer e_181;
    integer fill_182[7];
    integer e_183;
    integer fill_184[1];
    integer e_185;
    integer fill_186[4];
    integer e_187[2];
    integer fill_188[4];
    integer e_189[3];
    integer fill_190[28];
    integer e_191[7];
    integer fill_192[10];
    integer e_193;
    integer fill_194[3];
    integer e_195[3];
    integer fill_196[7];
    integer e_197;
    integer fill_198[3];
    integer e_199;
    integer fill_200[11];
    integer e_201[3];
    integer fill_202[1];
    integer e_203[2];
    integer fill_204[8];
    integer e_205;
    integer fill_206[4];
    integer e_207[3];
    integer fill_208[9];
    integer e_209[3];
    integer fill_210[3];
    integer e_211[5];
    integer fill_212[5];
    integer e_213;
    integer fill_214[2];
    integer e_215;
    integer fill_216[1];
    integer e_217[2];
    integer fill_218[6];
    integer e_219;
    integer fill_220[2];
    integer e_221;
    integer fill_222[6];
    integer e_223[3];
    integer fill_224[2];
    integer e_225;
    integer fill_226[1];
    integer e_227;
    integer fill_228[2];
    integer e_229;
    integer fill_230[3];
    integer e_231;
    integer fill_232[3];
    integer e_233[3];
    integer fill_234[11];
    integer e_235;
    integer fill_236[3];
    integer e_237;
    integer fill_238[4];
    integer e_239;
    integer fill_240[7];
    integer e_241;
    integer fill_242[19];
    integer e_243;
    integer fill_244[6];
    integer e_245;
    integer fill_246[8];
    integer e_247;
    integer fill_248[2];
    integer e_249;
    integer fill_250[6];
    integer e_251[2];
    integer fill_252[2];
    integer e_253;
    integer fill_254[2];
    integer e_255;
    integer fill_256[12];
    integer e_257;
    integer fill_258[10];
    integer e_259;
    integer fill_260[1];
    integer e_261;
    integer fill_262[1];
    integer e_263;
    integer fill_264[5];
    integer e_265;
    integer fill_266[9];
    integer e_267;
    integer fill_268[3];
    integer e_269;
    integer fill_270[8];
    integer e_271[3];
    integer fill_272[1];
    integer e_273[3];
    integer fill_274[1];
    integer e_275[2];
    integer fill_276[3];
    integer e_277;
    integer fill_278[2];
    integer e_279;
    integer fill_280[9];
    integer e_281[2];
    integer fill_282[1];
    integer e_283[2];
    integer fill_284[11];
    integer e_285;
    integer fill_286[4];
    integer e_287;
    integer fill_288[3];
    integer e_289;
    integer fill_290[14];
    integer e_291;
    integer fill_292[1];
    integer e_293;
    integer fill_294[5];
    integer e_295;
    integer fill_296[12];
    integer e_297;
    integer fill_298[23];
    integer e_299;
    integer fill_300[3];
    integer e_301;
    integer fill_302[1];
    integer e_303[2];
    integer fill_304[1];
    integer e_305[2];
    integer fill_306[2];
    integer e_307;
    integer fill_308[14];
    integer e_309;
    integer fill_310[7];
    integer e_311;
    integer fill_312[26];
    integer e_313;
    integer fill_314[5];
    integer e_315;
    integer fill_316[1];
    integer e_317;
    integer fill_318[7];
    integer e_319;
    integer fill_320[6];
    integer e_321;
    integer fill_322[14];
    integer e_323;
    integer fill_324[9];
    integer e_325[2];
    integer fill_326[3];
    integer e_327[6];
    integer fill_328[1];
    integer e_329[2];
    integer fill_330[7];
    integer e_331;
    integer fill_332[9];
    integer e_333[7];
    integer fill_334[10];
    integer e_335;
    integer fill_336[4];
    integer e_337;
    integer fill_338[2];
    integer e_339;
    integer fill_340[13];
    integer e_341;
    integer fill_342[2];
    integer e_343;
    integer fill_344[9];
    integer e_345;
    integer fill_346[1];
    integer e_347;
    integer fill_348[2];
    integer e_349;
    integer fill_350[1];
    integer e_351;
    integer fill_352[7];
    integer e_353[2];
    integer fill_354[5];
    integer e_355;
    integer fill_356[4];
    integer e_357;
    integer fill_358[12];
    integer e_359[3];
    integer fill_360[10];
    integer e_361[2];
    integer fill_362[3];
    integer e_363;
    integer fill_364[1];
    integer e_365[2];
    integer fill_366[15];
    integer e_367[2];
    integer fill_368[24];
    integer e_369;
    integer fill_370[3];
    integer e_371;
    integer fill_372[5];
    integer e_373;
    integer fill_374[19];
    integer e_375;
    integer fill_376[9];
    integer e_377[2];
    integer fill_378[7];
    integer e_379;
    integer fill_380[1];
    integer e_381[2];
    integer fill_382[1];
    integer e_383;
    integer fill_384[10];
    integer e_385;
    integer fill_386[26];
    integer e_387;
    integer fill_388[5];
    integer e_389;
    integer fill_390[1];
    integer e_391;
    integer fill_392[5];
    integer e_393;
    integer fill_394[2];
    integer e_395[2];
    integer fill_396[3];
    integer e_397;
    integer fill_398[2];
    integer e_399;
    integer fill_400[20];
    integer e_401;
    integer fill_402[1];
    integer e_403;
    integer fill_404[5];
    integer e_405;
    integer fill_406[3];
    integer e_407;
    integer fill_408[12];
    integer e_409[2];
    integer fill_410[6];
    integer e_411;
    integer fill_412[12];
    integer e_413;
    integer fill_414[1];
    integer e_415;
    integer fill_416[7];
    integer e_417;
    integer fill_418[3];
    integer e_419[7];
    integer fill_420[6];
    integer e_421;
    integer fill_422[11];
    integer e_423;
    integer fill_424[9];
    integer e_425;
    integer fill_426[1];
    integer e_427[2];
    integer fill_428[1];
    integer e_429;
    integer fill_430[3];
    integer e_431;
    integer fill_432[2];
    integer e_433[6];
    integer fill_434[9];
    integer e_435;
    integer fill_436[9];
    integer e_437;
    integer fill_438[11];
    integer e_439;
    integer fill_440[1];
    integer e_441[2];
    integer fill_442[6];
    integer e_443;
    integer fill_444[5];
    integer e_445;
    integer fill_446[5];
    integer e_447;
    integer fill_448[6];
    integer e_449;
    integer fill_450[2];
    integer e_451;
    integer fill_452[2];
    integer e_453;
    integer fill_454[4];
    integer e_455[2];
    integer fill_456[6];
    integer e_457;
    integer fill_458[16];
    integer e_459;
    integer fill_460[3];
    integer e_461;
    integer fill_462[10];
    integer e_463[2];
    integer fill_464[8];
    integer e_465;
    integer fill_466[8];
    integer e_467;
    integer fill_468[2];
    integer e_469;
    integer fill_470[1];
    integer e_471;
    integer fill_472[11];
    integer e_473[2];
    integer fill_474[9];
    integer e_475;
    integer fill_476[3];
    integer e_477[2];
    integer fill_478[6];
    integer e_479;
    integer fill_480[1];
    integer e_481[4];
    integer fill_482[2];
    integer e_483;
    integer fill_484[3];
    integer e_485[3];
    integer fill_486[1];
    integer e_487;
    integer fill_488[9];
    integer e_489;
    integer fill_490[4];
    integer e_491[6];
    integer fill_492[8];
    integer e_493;
    integer fill_494[17];
    integer e_495;
    integer fill_496[7];
    integer e_497;
    integer fill_498[8];
    integer e_499;
    integer fill_500[4];
    integer e_501;
    integer fill_502[8];
    integer e_503;
    integer fill_504[1];
    integer e_505[2];
    integer fill_506[3];
    integer e_507;
    integer fill_508[1];
    integer e_509;
    integer fill_510[13];
    integer e_511[3];
    integer fill_512[8];
    integer e_513[2];
    integer fill_514[38];
    integer e_515;
    integer fill_516[15];
    integer e_517;
    integer fill_518[17];
    integer e_519[2];
    integer fill_520[1];
    integer e_521;
    integer fill_522[8];
    integer e_523[2];
    integer fill_524[1];
    integer e_525;
    integer fill_526[2];
    integer e_527;
    integer fill_528[13];
    integer e_529;
    integer fill_530[9];
    integer e_531;
    integer fill_532[6];
    integer e_533;
    integer fill_534[6];
    integer e_535;
    integer fill_536[16];
    integer e_537;
    integer fill_538[13];
    integer e_539[3];
    integer fill_540[10];
    integer e_541[2];
    integer fill_542[28];
    integer e_543;
    integer fill_544[4];
    integer e_545;
    integer fill_546[6];
    integer e_547;
    integer fill_548[3];
    integer e_549[2];
    integer fill_550[14];
    integer e_551;
    integer fill_552[4];
    integer e_553[2];
    integer fill_554[6];
    integer e_555;
    integer fill_556[2];
    integer e_557;
    integer fill_558[2];
    integer e_559;
    integer fill_560[6];
    integer e_561[2];
    integer fill_562[5];
    integer e_563[2];
    integer fill_564[4];
    integer e_565[6];
    integer fill_566[1];
    integer e_567[2];
    integer fill_568[3];
    integer e_569;
    integer fill_570[1];
    integer e_571[2];
    integer fill_572[2];
    integer e_573[2];
    integer fill_574[11];
    integer e_575;
    integer fill_576[1];
    integer e_577[9];
    integer fill_578[2];
    integer e_579;
    integer fill_580[1];
    integer e_581[4];
    integer fill_582[4];
    integer e_583[3];
    integer fill_584[11];
    integer e_585;
    integer fill_586[4];
    integer e_587;
    integer fill_588[2];
    integer e_589;
    integer fill_590[3];
    integer e_591;
    integer fill_592[1];
    integer e_593;
    integer fill_594[22];
    integer e_595;
    integer fill_596[11];
    integer e_597;
    integer fill_598[2];
    integer e_599;
    integer fill_600[5];
    integer e_601;
    integer fill_602[19];
    integer e_603[4];
    integer fill_604[2];
    integer e_605[2];
    integer fill_606[3];
    integer e_607;
    integer fill_608[8];
    integer e_609;
    integer fill_610[4];
    integer e_611[2];
    integer fill_612[5];
    integer e_613;
    integer fill_614[19];
    integer e_615;
    integer fill_616[3];
    integer e_617;
    integer fill_618[1];
    integer e_619[2];
    integer fill_620[3];
    integer e_621[4];
    integer fill_622[13];
    integer e_623;
    integer fill_624[1];
    integer e_625;
    integer fill_626[1];
    integer e_627;
    integer fill_628[24];
    integer e_629[2];
    integer fill_630[24];
    integer e_631;
    integer fill_632[5];
    integer e_633[2];
    integer fill_634[7];
    integer e_635;
    integer fill_636[1];
    integer e_637;
    integer fill_638[22];
    integer e_639;
    integer fill_640[12];
    integer e_641[3];
    integer fill_642[14];
    integer e_643;
    integer fill_644[6];
    integer e_645[3];
    integer fill_646[2];
    integer e_647;
    integer fill_648[17];
    integer e_649;
    integer fill_650[15];
    integer e_651;
    integer fill_652[2];
    integer e_653;
    integer fill_654[3];
    integer e_655;
    integer fill_656[2];
    integer e_657;
    integer fill_658[2];
    integer e_659;
    integer fill_660[2];
    integer e_661;
    integer fill_662[8];
    integer e_663;
    integer fill_664[16];
    integer e_665;
    integer fill_666[12];
    integer e_667[2];
    integer fill_668[1];
    integer e_669[2];
    integer fill_670[4];
    integer e_671;
    integer fill_672[7];
    integer e_673[2];
    integer fill_674[12];
    integer e_675;
    integer fill_676[4];
    integer e_677;
    integer fill_678[4];
    integer e_679;
    integer fill_680[9];
    integer e_681[2];
    integer fill_682[9];
    integer e_683;
    integer fill_684[9];
    integer e_685;
    integer fill_686[5];
    integer e_687;
    integer fill_688[12];
    integer e_689;
    integer fill_690[36];
    integer e_691[2];
    integer fill_692[5];
    integer e_693;
    integer fill_694[1];
    integer e_695[2];
    integer fill_696[3];
    integer e_697;
    integer fill_698[11];
    integer e_699;
    integer fill_700[6];
    } nametb_ = { 1, 56, 57, 169, 170, 3000, 1, 13, 14, 3000, 0, 10000, 10000,
	     10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 8000, 
	    12000, 7000, 11000, 11000, 11000, 11000, 11000, 11000, 11000, 
	    11000, 11000, 21000, 3000, 6000, 11000, 11000, 11000, 11000, 
	    11000, 11000, 11000, 11000, 11000, 15000, 9000, 13000, 5000, 
	    11000, 11000, 11000, 11000, 11000, 11000, 11000, 11000, 1000, 
	    2000, 24000, 4000, 38000, 32000, 25000, 26000, 45000, 19100, 
	    19101, 19102, 19103, 19104, 19105, 19106, 19107, 19108, 19109, 
	    19110, 19111, 19112, 19113, 19114, 19115, 19116, 19117, 19118, 
	    19119, 19120, 19121, 19122, 19123, 19124, 19125, 19126, 19127, 
	    19128, 19129, 19130, 19131, 19132, 19133, 19134, 19135, 19136, 
	    19137, 19138, 19139, 19140, 19141, 19142, 19143, 19144, 19145, 
	    19146, 19147, 19148, 19149, 19150, 19151, 19152, 19153, 19154, 
	    19155, 19156, 19157, 19158, 19159, 19160, 19161, 19162, 19163, 
	    19164, 19165, 19166, 19167, 19168, 19169, 19170, 19171, 19172, 
	    19173, 19174, 19175, 19176, 19177, 19178, 19179, 19180, 19193, 
	    19195, 19196, 19194, 19198, 19199, 19200, 19201, 19203, 19204, 
	    19202, 19207, 19011, 19012, 19003, 19208, 19209, 19211, 19212, 
	    19213, 19214, 19215, 19216, 19217, 19218, 19219, 19247, 19248, 
	    31000, 31000, 31000, 31000, {0}, 40000, {0}, 40000, 40056, {0}, 
	    35100, {0}, 35064, 40000, {0}, 35100, {0}, 39024, {0}, 40000, {0},
	     40053, {0}, 35187, {0}, 35132, {0}, 39003, {0}, 35054, {0}, 
	    40000, {0}, 35158, {0}, 35100, 40051, {0}, 35170, {0}, 40000, 
	    35069, {0}, 35100, 39004, {0}, 35026, 35100, {0}, 40057, {0}, 
	    35171, {0}, 39021, 35100, 40065, {0}, 39045, 40000, 35100, {0}, 
	    19050, {0}, 35017, {0}, 19185, {0}, 27001, {0}, 35100, {0}, 35069,
	     {0}, 18228, {0}, 18184, {0}, 18236, 35036, 35126, 35015, 18241, 
	    35100, 35155, 35159, 35001, 40000, {0}, 27004, 35006, 40028, {0}, 
	    40060, {0}, 40049, {0}, 18221, 40000, {0}, 35161, {0}, 35047, 
	    18190, {0}, 40009, {0}, 41001, {0}, 40026, {0}, 40034, {0}, 40000,
	     {0}, 40005, 39006, {0}, 35069, 35182, {0}, 35100, 40003, 40004, {
	    0}, 35100, {0}, 35071, {0}, 40000, {0}, 35100, {0}, 18189, 40048, 
	    {0}, 35188, {0}, 40030, {0}, 35073, 35030, 35100, 35162, 35188, {
	    0}, 35185, {0}, 35100, {0}, 18238, {0}, 35037, {0}, 18243, 35062, 
	    40056, {0}, 19042, {0}, 35041, {0}, 39048, {0}, 35147, 35100, {0},
	     35052, {0}, 18197, 18244, 35153, {0}, 35100, {0}, 18188, {0}, 
	    35044, {0}, 35100, {0}, 35048, 40000, {0}, 18224, 18230, {0}, 
	    35100, 35100, {0}, 40000, 18240, 35166, 40000, 35100, {0}, 29000, 
	    {0}, 35100, {0}, 40000, {0}, 35040, {0}, 43011, {0}, 18227, {0}, 
	    18191, {0}, 18235, {0}, 35130, {0}, 35100, 40062, {0}, 39010, {0},
	     40000, {0}, 40000, {0}, 40000, 40000, {0}, 35045, 35046, 35047, 
	    35100, {0}, 35100, {0}, 35009, {0}, 35014, {0}, 35130, {0}, 40036,
	     35100, {0}, 40011, 35043, 40058, {0}, 35021, 35129, 40000, 40000,
	     19043, 35031, 35128, {0}, 35100, {0}, 18249, 35069, 40063, {0}, 
	    40000, {0}, 35100, {0}, 40000, 40064, 46000, {0}, 35100, 40029, {
	    0}, 35035, {0}, 40000, 35100, 35144, {0}, 35012, 18245, 40000, {0}
	    , 35050, 39015, 35100, 35163, 40000, {0}, 40000, {0}, 40000, {0}, 
	    35042, 18210, {0}, 37000, {0}, 40032, {0}, 35004, 18229, 35100, {
	    0}, 18222, {0}, 18237, {0}, 35149, {0}, 35100, {0}, 35136, 35147, 
	    40034, {0}, 19041, {0}, 35100, {0}, 27003, {0}, 35100, {0}, 35100,
	     {0}, 40027, {0}, 35023, {0}, 35037, {0}, 35003, 40000, {0}, 
	    35100, {0}, 35130, {0}, 28000, {0}, 35100, {0}, 35100, {0}, 35100,
	     {0}, 40000, {0}, 35100, {0}, 35100, {0}, 35100, 35157, 40000, {0}
	    , 19014, 35145, 40000, {0}, 18181, 40000, {0}, 35048, {0}, 40000, 
	    {0}, 35100, 40059, {0}, 40000, 39014, {0}, 35100, {0}, 39028, {0},
	     40010, {0}, 35003, {0}, 40055, {0}, 35020, {0}, 40034, {0}, 
	    40000, {0}, 40052, {0}, 40002, 40060, {0}, 40000, 35100, {0}, 
	    35170, {0}, 40000, {0}, 40000, {0}, 27002, {0}, 35067, {0}, 35024,
	     {0}, 35060, {0}, 35045, {0}, 43029, {0}, 39018, 35100, {0}, 
	    18226, 18232, 35183, 35069, 40000, 35100, {0}, 18246, 40000, {0}, 
	    42000, {0}, 39012, 35001, 35100, 35100, 35098, 40008, 35148, {0}, 
	    35003, {0}, 40056, {0}, 35032, {0}, 27006, {0}, 35100, {0}, 35131,
	     {0}, 43026, {0}, 35165, {0}, 35100, {0}, 35100, 40000, {0}, 
	    35039, {0}, 39050, {0}, 35100, 40000, 40000, {0}, 35168, 39002, {
	    0}, 35100, {0}, 35100, 40000, {0}, 35100, 35181, {0}, 40000, {0}, 
	    18220, {0}, 35051, {0}, 35025, {0}, 35029, 35138, {0}, 40000, {0},
	     35135, 40000, {0}, 35133, {0}, 19017, {0}, 18186, {0}, 39047, {0}
	    , 35028, {0}, 35100, {0}, 40000, 35100, {0}, 39046, {0}, 35127, {
	    0}, 40000, {0}, 35100, {0}, 40000, {0}, 35141, {0}, 27000, 40000, 
	    {0}, 40000, {0}, 40022, {0}, 35057, {0}, 35066, {0}, 18182, 18223,
	     18233, 18234, 35010, 40035, 40000, {0}, 35137, {0}, 35059, {0}, 
	    35143, {0}, 40000, 35164, {0}, 35001, {0}, 40000, {0}, 35007, 
	    18242, 35014, 35016, 35038, 35038, {0}, 35100, {0}, 35027, {0}, 
	    35100, {0}, 39017, 40000, {0}, 35100, {0}, 35100, {0}, 40000, {0},
	     40066, {0}, 35056, {0}, 35075, {0}, 35100, 35100, {0}, 40000, {0}
	    , 40047, {0}, 40007, {0}, 35050, 35022, {0}, 39020, {0}, 35100, {
	    0}, 35094, {0}, 35154, {0}, 35172, 40000, {0}, 39009, {0}, 40025, 
	    35034, {0}, 40000, {0}, 35074, 19020, 19045, 35100, {0}, 40000, {
	    0}, 40000, 40037, 40040, {0}, 35100, {0}, 40013, {0}, 19015, 
	    19016, 40000, 40000, 40034, 35100, {0}, 40000, {0}, 27005, {0}, 
	    35049, {0}, 40054, {0}, 39019, {0}, 39008, {0}, 35100, 35180, {0},
	     35072, {0}, 35180, {0}, 40000, 35100, 40000, {0}, 19019, 40000, {
	    0}, 35018, {0}, 35139, {0}, 35100, 40000, {0}, 35160, {0}, 40000, 
	    35186, {0}, 19021, {0}, 40000, {0}, 19042, {0}, 19018, {0}, 40000,
	     {0}, 40000, {0}, 40000, {0}, 30000, 40000, 40060, {0}, 35100, 
	    40000, {0}, 40000, {0}, 35100, {0}, 35046, {0}, 35063, 35100, {0},
	     39005, {0}, 35070, 35100, {0}, 35069, {0}, 35065, {0}, 35011, {0}
	    , 40000, 40000, {0}, 35169, 40000, {0}, 35097, 35100, 18239, 
	    40000, 40031, 35100, {0}, 40000, 35100, {0}, 35100, {0}, 35100, 
	    35156, {0}, 40000, 35100, {0}, 35100, {0}, 35013, 35068, 35151, 
	    35152, 39001, 40000, 40000, 40000, 40000, {0}, 35100, {0}, 35033, 
	    40000, 40000, 19024, {0}, 27000, 35100, 35100, {0}, 41002, {0}, 
	    40000, {0}, 35100, {0}, 40000, {0}, 35053, {0}, 35034, {0}, 40000,
	     {0}, 35184, {0}, 35100, {0}, 19044, 19045, 35100, 40034, {0}, 
	    18192, 40023, {0}, 40060, {0}, 40025, {0}, 35005, 35005, {0}, 
	    40001, {0}, 40000, {0}, 35100, {0}, 35100, 40006, {0}, 35100, 
	    19039, 35100, 39049, {0}, 40000, {0}, 35100, {0}, 35100, {0}, 
	    18225, 18231, {0}, 40000, {0}, 35100, 40046, {0}, 35096, {0}, 
	    33000, {0}, 35019, {0}, 43030, 35167, 40000, {0}, 35055, {0}, 
	    35013, 40024, 40038, {0}, 35100, {0}, 35146, {0}, 35008, {0}, 
	    35016, {0}, 18187, {0}, 40060, {0}, 39027, {0}, 40034, {0}, 35150,
	     {0}, 43013, {0}, 39007, 40033, {0}, 40059, 35100, {0}, 35134, {0}
	    , 35140, 40000, {0}, 35100, {0}, 35100, {0}, 40000, {0}, 35142, 
	    35100, {0}, 35058, {0}, 40000, {0}, 35130, {0}, 35100, {0}, 35095,
	     40000, {0}, 40000, {0}, 35100, 35100, {0}, 35100, {0}, 35061 };

struct {
    char e_1[1014];
    char fill_2[18];
    char e_3[6];
    char fill_4[12];
    char e_5[12];
    char fill_6[36];
    char e_7[6];
    char fill_8[138];
    char e_9[12];
    char fill_10[12];
    char e_11[6];
    char fill_12[84];
    char e_13[6];
    char fill_14[60];
    char e_15[6];
    char fill_16[42];
    char e_17[6];
    char fill_18[6];
    char e_19[6];
    char fill_20[48];
    char e_21[6];
    char fill_22[72];
    char e_23[6];
    char fill_24[18];
    char e_25[6];
    char fill_26[6];
    char e_27[6];
    char fill_28[24];
    char e_29[6];
    char fill_30[72];
    char e_31[12];
    char fill_32[48];
    char e_33[6];
    char fill_34[36];
    char e_35[12];
    char fill_36[36];
    char e_37[12];
    char fill_38[36];
    char e_39[12];
    char fill_40[30];
    char e_41[6];
    char fill_42[6];
    char e_43[6];
    char fill_44[30];
    char e_45[18];
    char fill_46[6];
    char e_47[18];
    char fill_48[36];
    char e_49[6];
    char fill_50[12];
    char e_51[6];
    char fill_52[36];
    char e_53[6];
    char fill_54[132];
    char e_55[6];
    char fill_56[84];
    char e_57[6];
    char fill_58[36];
    char e_59[6];
    char fill_60[54];
    char e_61[6];
    char fill_62[18];
    char e_63[6];
    char fill_64[6];
    char e_65[60];
    char fill_66[12];
    char e_67[18];
    char fill_68[12];
    char e_69[6];
    char fill_70[48];
    char e_71[6];
    char fill_72[12];
    char e_73[12];
    char fill_74[6];
    char e_75[6];
    char fill_76[96];
    char e_77[12];
    char fill_78[66];
    char e_79[6];
    char fill_80[18];
    char e_81[6];
    char fill_82[6];
    char e_83[6];
    char fill_84[12];
    char e_85[6];
    char fill_86[12];
    char e_87[6];
    char fill_88[18];
    char e_89[12];
    char fill_90[12];
    char e_91[12];
    char fill_92[6];
    char e_93[18];
    char fill_94[12];
    char e_95[6];
    char fill_96[24];
    char e_97[6];
    char fill_98[6];
    char e_99[6];
    char fill_100[6];
    char e_101[6];
    char fill_102[24];
    char e_103[12];
    char fill_104[12];
    char e_105[6];
    char fill_106[30];
    char e_107[6];
    char fill_108[30];
    char e_109[30];
    char fill_110[30];
    char e_111[6];
    char fill_112[48];
    char e_113[6];
    char fill_114[12];
    char e_115[6];
    char fill_116[6];
    char e_117[6];
    char fill_118[6];
    char e_119[18];
    char fill_120[18];
    char e_121[6];
    char fill_122[24];
    char e_123[6];
    char fill_124[24];
    char e_125[6];
    char fill_126[96];
    char e_127[12];
    char fill_128[48];
    char e_129[6];
    char fill_130[24];
    char e_131[18];
    char fill_132[54];
    char e_133[6];
    char fill_134[24];
    char e_135[6];
    char fill_136[6];
    char e_137[6];
    char fill_138[6];
    char e_139[6];
    char fill_140[72];
    char e_141[12];
    char fill_142[114];
    char e_143[12];
    char fill_144[18];
    char e_145[12];
    char fill_146[6];
    char e_147[30];
    char fill_148[84];
    char e_149[6];
    char fill_150[66];
    char e_151[6];
    char fill_152[54];
    char e_153[6];
    char fill_154[156];
    char e_155[6];
    char fill_156[30];
    char e_157[6];
    char fill_158[12];
    char e_159[6];
    char fill_160[18];
    char e_161[6];
    char fill_162[6];
    char e_163[6];
    char fill_164[18];
    char e_165[6];
    char fill_166[6];
    char e_167[12];
    char fill_168[96];
    char e_169[6];
    char fill_170[18];
    char e_171[6];
    char fill_172[48];
    char e_173[6];
    char fill_174[18];
    char e_175[12];
    char fill_176[42];
    char e_177[24];
    char fill_178[36];
    char e_179[6];
    char fill_180[6];
    char e_181[6];
    char fill_182[42];
    char e_183[6];
    char fill_184[6];
    char e_185[6];
    char fill_186[24];
    char e_187[12];
    char fill_188[24];
    char e_189[18];
    char fill_190[168];
    char e_191[42];
    char fill_192[60];
    char e_193[6];
    char fill_194[18];
    char e_195[18];
    char fill_196[42];
    char e_197[6];
    char fill_198[18];
    char e_199[6];
    char fill_200[66];
    char e_201[18];
    char fill_202[6];
    char e_203[12];
    char fill_204[48];
    char e_205[6];
    char fill_206[24];
    char e_207[18];
    char fill_208[54];
    char e_209[18];
    char fill_210[18];
    char e_211[30];
    char fill_212[30];
    char e_213[6];
    char fill_214[12];
    char e_215[6];
    char fill_216[6];
    char e_217[12];
    char fill_218[36];
    char e_219[6];
    char fill_220[12];
    char e_221[6];
    char fill_222[36];
    char e_223[18];
    char fill_224[12];
    char e_225[6];
    char fill_226[6];
    char e_227[6];
    char fill_228[12];
    char e_229[6];
    char fill_230[18];
    char e_231[6];
    char fill_232[18];
    char e_233[18];
    char fill_234[66];
    char e_235[6];
    char fill_236[18];
    char e_237[6];
    char fill_238[24];
    char e_239[6];
    char fill_240[42];
    char e_241[6];
    char fill_242[114];
    char e_243[6];
    char fill_244[36];
    char e_245[6];
    char fill_246[48];
    char e_247[6];
    char fill_248[12];
    char e_249[6];
    char fill_250[36];
    char e_251[12];
    char fill_252[12];
    char e_253[6];
    char fill_254[12];
    char e_255[6];
    char fill_256[72];
    char e_257[6];
    char fill_258[60];
    char e_259[6];
    char fill_260[6];
    char e_261[6];
    char fill_262[6];
    char e_263[6];
    char fill_264[30];
    char e_265[6];
    char fill_266[54];
    char e_267[6];
    char fill_268[18];
    char e_269[6];
    char fill_270[48];
    char e_271[18];
    char fill_272[6];
    char e_273[18];
    char fill_274[6];
    char e_275[12];
    char fill_276[18];
    char e_277[6];
    char fill_278[12];
    char e_279[6];
    char fill_280[54];
    char e_281[12];
    char fill_282[6];
    char e_283[12];
    char fill_284[66];
    char e_285[6];
    char fill_286[24];
    char e_287[6];
    char fill_288[18];
    char e_289[6];
    char fill_290[84];
    char e_291[6];
    char fill_292[6];
    char e_293[6];
    char fill_294[30];
    char e_295[6];
    char fill_296[72];
    char e_297[6];
    char fill_298[138];
    char e_299[6];
    char fill_300[18];
    char e_301[6];
    char fill_302[6];
    char e_303[12];
    char fill_304[6];
    char e_305[12];
    char fill_306[12];
    char e_307[6];
    char fill_308[84];
    char e_309[6];
    char fill_310[42];
    char e_311[6];
    char fill_312[156];
    char e_313[6];
    char fill_314[30];
    char e_315[6];
    char fill_316[6];
    char e_317[6];
    char fill_318[42];
    char e_319[6];
    char fill_320[36];
    char e_321[6];
    char fill_322[84];
    char e_323[6];
    char fill_324[54];
    char e_325[12];
    char fill_326[18];
    char e_327[36];
    char fill_328[6];
    char e_329[12];
    char fill_330[42];
    char e_331[6];
    char fill_332[54];
    char e_333[42];
    char fill_334[60];
    char e_335[6];
    char fill_336[24];
    char e_337[6];
    char fill_338[12];
    char e_339[6];
    char fill_340[78];
    char e_341[6];
    char fill_342[12];
    char e_343[6];
    char fill_344[54];
    char e_345[6];
    char fill_346[6];
    char e_347[6];
    char fill_348[12];
    char e_349[6];
    char fill_350[6];
    char e_351[6];
    char fill_352[42];
    char e_353[12];
    char fill_354[30];
    char e_355[6];
    char fill_356[24];
    char e_357[6];
    char fill_358[72];
    char e_359[18];
    char fill_360[60];
    char e_361[12];
    char fill_362[18];
    char e_363[6];
    char fill_364[6];
    char e_365[12];
    char fill_366[90];
    char e_367[12];
    char fill_368[144];
    char e_369[6];
    char fill_370[18];
    char e_371[6];
    char fill_372[30];
    char e_373[6];
    char fill_374[114];
    char e_375[6];
    char fill_376[54];
    char e_377[12];
    char fill_378[42];
    char e_379[6];
    char fill_380[6];
    char e_381[12];
    char fill_382[6];
    char e_383[6];
    char fill_384[60];
    char e_385[6];
    char fill_386[156];
    char e_387[6];
    char fill_388[30];
    char e_389[6];
    char fill_390[6];
    char e_391[6];
    char fill_392[30];
    char e_393[6];
    char fill_394[12];
    char e_395[12];
    char fill_396[18];
    char e_397[6];
    char fill_398[12];
    char e_399[6];
    char fill_400[120];
    char e_401[6];
    char fill_402[6];
    char e_403[6];
    char fill_404[30];
    char e_405[6];
    char fill_406[18];
    char e_407[6];
    char fill_408[72];
    char e_409[12];
    char fill_410[36];
    char e_411[6];
    char fill_412[72];
    char e_413[6];
    char fill_414[6];
    char e_415[6];
    char fill_416[42];
    char e_417[6];
    char fill_418[18];
    char e_419[42];
    char fill_420[36];
    char e_421[6];
    char fill_422[66];
    char e_423[6];
    char fill_424[54];
    char e_425[6];
    char fill_426[6];
    char e_427[12];
    char fill_428[6];
    char e_429[6];
    char fill_430[18];
    char e_431[6];
    char fill_432[12];
    char e_433[36];
    char fill_434[54];
    char e_435[6];
    char fill_436[54];
    char e_437[6];
    char fill_438[66];
    char e_439[6];
    char fill_440[6];
    char e_441[12];
    char fill_442[36];
    char e_443[6];
    char fill_444[30];
    char e_445[6];
    char fill_446[30];
    char e_447[6];
    char fill_448[36];
    char e_449[6];
    char fill_450[12];
    char e_451[6];
    char fill_452[12];
    char e_453[6];
    char fill_454[24];
    char e_455[12];
    char fill_456[36];
    char e_457[6];
    char fill_458[96];
    char e_459[6];
    char fill_460[18];
    char e_461[6];
    char fill_462[60];
    char e_463[12];
    char fill_464[48];
    char e_465[6];
    char fill_466[48];
    char e_467[6];
    char fill_468[12];
    char e_469[6];
    char fill_470[6];
    char e_471[6];
    char fill_472[66];
    char e_473[12];
    char fill_474[54];
    char e_475[6];
    char fill_476[18];
    char e_477[12];
    char fill_478[36];
    char e_479[6];
    char fill_480[6];
    char e_481[24];
    char fill_482[12];
    char e_483[6];
    char fill_484[18];
    char e_485[18];
    char fill_486[6];
    char e_487[6];
    char fill_488[54];
    char e_489[6];
    char fill_490[24];
    char e_491[36];
    char fill_492[48];
    char e_493[6];
    char fill_494[102];
    char e_495[6];
    char fill_496[42];
    char e_497[6];
    char fill_498[48];
    char e_499[6];
    char fill_500[24];
    char e_501[6];
    char fill_502[48];
    char e_503[6];
    char fill_504[6];
    char e_505[12];
    char fill_506[18];
    char e_507[6];
    char fill_508[6];
    char e_509[6];
    char fill_510[78];
    char e_511[18];
    char fill_512[48];
    char e_513[12];
    char fill_514[228];
    char e_515[6];
    char fill_516[90];
    char e_517[6];
    char fill_518[102];
    char e_519[12];
    char fill_520[6];
    char e_521[6];
    char fill_522[48];
    char e_523[12];
    char fill_524[6];
    char e_525[6];
    char fill_526[12];
    char e_527[6];
    char fill_528[78];
    char e_529[6];
    char fill_530[54];
    char e_531[6];
    char fill_532[36];
    char e_533[6];
    char fill_534[36];
    char e_535[6];
    char fill_536[96];
    char e_537[6];
    char fill_538[78];
    char e_539[18];
    char fill_540[60];
    char e_541[12];
    char fill_542[168];
    char e_543[6];
    char fill_544[24];
    char e_545[6];
    char fill_546[36];
    char e_547[6];
    char fill_548[18];
    char e_549[12];
    char fill_550[84];
    char e_551[6];
    char fill_552[24];
    char e_553[12];
    char fill_554[36];
    char e_555[6];
    char fill_556[12];
    char e_557[6];
    char fill_558[12];
    char e_559[6];
    char fill_560[36];
    char e_561[12];
    char fill_562[30];
    char e_563[12];
    char fill_564[24];
    char e_565[36];
    char fill_566[6];
    char e_567[12];
    char fill_568[18];
    char e_569[6];
    char fill_570[6];
    char e_571[12];
    char fill_572[12];
    char e_573[12];
    char fill_574[66];
    char e_575[6];
    char fill_576[6];
    char e_577[54];
    char fill_578[12];
    char e_579[6];
    char fill_580[6];
    char e_581[24];
    char fill_582[24];
    char e_583[18];
    char fill_584[66];
    char e_585[6];
    char fill_586[24];
    char e_587[6];
    char fill_588[12];
    char e_589[6];
    char fill_590[18];
    char e_591[6];
    char fill_592[6];
    char e_593[6];
    char fill_594[132];
    char e_595[6];
    char fill_596[66];
    char e_597[6];
    char fill_598[12];
    char e_599[6];
    char fill_600[30];
    char e_601[6];
    char fill_602[114];
    char e_603[24];
    char fill_604[12];
    char e_605[12];
    char fill_606[18];
    char e_607[6];
    char fill_608[48];
    char e_609[6];
    char fill_610[24];
    char e_611[12];
    char fill_612[30];
    char e_613[6];
    char fill_614[114];
    char e_615[6];
    char fill_616[18];
    char e_617[6];
    char fill_618[6];
    char e_619[12];
    char fill_620[18];
    char e_621[24];
    char fill_622[78];
    char e_623[6];
    char fill_624[6];
    char e_625[6];
    char fill_626[6];
    char e_627[6];
    char fill_628[144];
    char e_629[12];
    char fill_630[144];
    char e_631[6];
    char fill_632[30];
    char e_633[12];
    char fill_634[42];
    char e_635[6];
    char fill_636[6];
    char e_637[6];
    char fill_638[132];
    char e_639[6];
    char fill_640[72];
    char e_641[18];
    char fill_642[84];
    char e_643[6];
    char fill_644[36];
    char e_645[18];
    char fill_646[12];
    char e_647[6];
    char fill_648[102];
    char e_649[6];
    char fill_650[90];
    char e_651[6];
    char fill_652[12];
    char e_653[6];
    char fill_654[18];
    char e_655[6];
    char fill_656[12];
    char e_657[6];
    char fill_658[12];
    char e_659[6];
    char fill_660[12];
    char e_661[6];
    char fill_662[48];
    char e_663[6];
    char fill_664[96];
    char e_665[6];
    char fill_666[72];
    char e_667[12];
    char fill_668[6];
    char e_669[12];
    char fill_670[24];
    char e_671[6];
    char fill_672[42];
    char e_673[12];
    char fill_674[72];
    char e_675[6];
    char fill_676[24];
    char e_677[6];
    char fill_678[24];
    char e_679[6];
    char fill_680[54];
    char e_681[12];
    char fill_682[54];
    char e_683[6];
    char fill_684[54];
    char e_685[6];
    char fill_686[30];
    char e_687[6];
    char fill_688[72];
    char e_689[6];
    char fill_690[216];
    char e_691[12];
    char fill_692[30];
    char e_693[6];
    char fill_694[6];
    char e_695[12];
    char fill_696[18];
    char e_697[6];
    char fill_698[66];
    char e_699[6];
    char fill_700[36];
    char e_701[156];
    char fill_702[35844];
    } cnamtb_ = { "      0     1     2     3     4     5     6     7     8  "
	    "   9     =     '     +     A     B     C     D     E     F     G"
	    "     H     I     .     )     -     J     K     L     M     N    "
	    " O     P     Q     R     $     *           /     S     T     U  "
	    "   V     W     X     Y     Z     ,     (     LTERM RTERM MCLTRMD"
	    "BLASTDOT   KREUZ CONASTUNDEF APT001APT003APT004APT005APT006APT00"
	    "7APT008APT009APT010APT011APT012APT014APT015APT016APT017APT018APT"
	    "019APT020APT021APT022APT023APT024APT025APT026APT027APT028APT029A"
	    "PT030APT031APT032APT033APT035APT036APT037APT038APT039APT040APT04"
	    "4APT045APT046APT047APT048APT049APT050APT051APT052APT053APT054APT"
	    "055APT056APT057APT058APT060APT061APT062APT063APT064APT065APT066A"
	    "PT067APT068APT073APT075APT077APT078APT079APT081APT083APT085APT08"
	    "7APT088APT090APT092APT093APT094APT100APT200APT201APT298APT299APT"
	    "041APT043APT295APT042APT069APT070APT071APT072APT074APT034DEFEXTA"
	    "PT101NDTESTCOMP3DTLON  GOTOPNAPT105APT106TRANSFAPT104APT102APT10"
	    "3APT107APT013APT108APT109APT110LOGIF .AC.  APTER $21T$1$$TAB ", {
	    0}, "INSERT", {0}, "CORNFDPTONLY", {0}, "DRILL ", {0}, "OMIT  TM"
	    "ARK ", {0}, "FWD   ", {0}, "SUBSCR", {0}, "GOCLER", {0}, "TLNDON",
	     {0}, "NPS   ", {0}, "SMESH ", {0}, "CYLNDR", {0}, "GRID  ", {0}, 
	    "STOP  ", {0}, "AWAY  ", {0}, "SADDLE2DCALC", {0}, "UCONST", {0}, 
	    "REWINDPVAL  ", {0}, "CIRCULCIRCLE", {0}, "RTHETACIRLIN", {0}, 
	    "READ  ", {0}, "RELTOL", {0}, "REAL  REAM  AVCTRL", {0}, "AVCXXX"
	    "OVPLOTREAR  ", {0}, "PUNCH ", {0}, "CENTER", {0}, "DDLIM ", {0}, 
	    ".EQ   ", {0}, "XCOORD", {0}, "SVAL  ", {0}, "COSB  ", {0}, "COS"
	    "F  ", {0}, "COSHF SCALE SCALARINTERCINTF  INTENSSCALOPBACK  CS  "
	    "  INTCOD", {0}, ".LE   INTOF INTOL ", {0}, "INTSEC", {0}, "TITLES"
	    , {0}, "LOG10FPPLOT ", {0}, "INIT  ", {0}, "ZSMALLLOGF  ", {0}, 
	    "CUT   ", {0}, "IF    ", {0}, "GODLTA", {0}, "GODOWN", {0}, "OPP"
	    "LOT", {0}, "TLOFPSHYPERB", {0}, "VVAL  TA    ", {0}, "SETANGTLON"
	    "  TLONPS", {0}, "OPEN  ", {0}, "CUTANG", {0}, "CUTCOM", {0}, 
	    "SETOOL", {0}, "LNTHF POCKET", {0}, "UVPDS ", {0}, "CUTTER", {0}, 
	    "WITH  SPLINESTEP  STEPOVUVPPS ", {0}, "NDS   ", {0}, "DARK  ", {
	    0}, "MINF  ", {0}, "YZPLAN", {0}, "SPATF AVOID REMARK", {0}, 
	    "PRINT ", {0}, "MINUS ", {0}, "GFTXXX", {0}, "DSTAN RAIL  ", {0}, 
	    "4PT1SL", {0}, "ANGLF ANGLB ANGLE ", {0}, "LIGHT ", {0}, "ERROR ",
	     {0}, "LENGTH", {0}, "CHUCK ", {0}, "ZXPLANMDWRIT", {0}, "COTANF"
	    "COTANB", {0}, "HOLDERXYVIEW", {0}, "MODE  MODF  PICKFDPICKUPMODI"
	    "FY", {0}, ".AND  ", {0}, "TPI   ", {0}, "FEDRAT", {0}, "CROSS ", {
	    0}, "TABCYL", {0}, "SINB  ", {0}, "SINF  ", {0}, "SINHF ", {0}, 
	    "TABPRT", {0}, "IPR   TLPROJ", {0}, "GCONIC", {0}, "CYCLE ", {0}, 
	    "DELAY ", {0}, "DELETESAFETY", {0}, "NEGX  NEGY  NEGZ  DASH  ", {
	    0}, "NOW   ", {0}, "RIGHT ", {0}, "XLARGE", {0}, "AVPRT ", {0}, 
	    "FROM  FRONT ", {0}, "NDTESTUNIT  UNITS ", {0}, "OUT   NOLISTEND"
	    "   MAGTAPCALL  TRFORMLISTON", {0}, "TYPE  ", {0}, "CLDATFCLDATAC"
	    "LDAT ", {0}, "LPRINT", {0}, "ENDARC", {0}, "ENDMDICHKSRFOBTAIN", {
	    0}, "ZAXIS OUTTOL", {0}, "INVERS", {0}, "COUPLEPARAB PARAM ", {0},
	     "PARLELPARMF DRAFT ", {0}, "ALL   PARSRFPART  FEED  PARTNO", {0},
	     "PLUNGE", {0}, "DRAWLI", {0}, "PLUS  NUMF  ", {0}, "TERMAC", {0},
	     "NUMPTS", {0}, "PSTAN TANB  FLOOD ", {0}, "TANF  ", {0}, "TANHF "
	    , {0}, "FLOW  ", {0}, "TANON ", {0}, "TANSPLTANTO GOFWD ", {0}, 
	    "PSIS  ", {0}, "SIDE  ", {0}, ".GE   ", {0}, "FOURPT", {0}, "RED"
	    "   ", {0}, "TOLER ", {0}, "NOX   ", {0}, "YZROT ", {0}, "TO    D"
	    "EBUGG", {0}, "CAM   ", {0}, "SSTEST", {0}, ".NOT  ", {0}, "CAXIS "
	    , {0}, "ANTSPI", {0}, "LITE  ", {0}, "CAMERA", {0}, "NOMORE", {0},
	     "BINARY", {0}, "NOBND CLEARSCLEARP", {0}, "CLPRNTBINORMAIR   ", {
	    0}, "ABSF  ROTABL", {0}, "ZXROT ", {0}, "ROTHED", {0}, "ROTREFSC"
	    "ON  ", {0}, "ZERO  QADRIC", {0}, "PTSLOP", {0}, "OBJECT", {0}, 
	    "DNTCUT", {0}, "PAST  ", {0}, "PPOPTN", {0}, "IN    ", {0}, "GOR"
	    "GT ", {0}, "OPSKIP", {0}, "3DCALC", {0}, "TLRGT SMIL  ", {0}, 
	    "OPSTOPNIXIE ", {0}, "VCONST", {0}, "SELCTL", {0}, "ASLOPE", {0}, 
	    ".NE   ", {0}, "ARC   ", {0}, "NOY   ", {0}, "DECR  ", {0}, "XSM"
	    "ALL", {0}, "SSURF ", {0}, "MATRIXYCOORD", {0}, "ARCOSFARCOSBTV  "
	    "  TVAL  ARCSLPMAIN  ", {0}, "CANF  DWELL ", {0}, "CANON ", {0}, 
	    "RLDSRFDS    NOCLRPFULL  AUTO  AUTOPSGENCUR", {0}, "ON    ", {0}, 
	    "TUNEUP", {0}, "LEFT  ", {0}, ".LT   ", {0}, "BLUE  ", {0}, "PAT"
	    "CH ", {0}, "PATERN", {0}, "PATH  ", {0}, "COLLET", {0}, "TAP   U"
	    "LOCKX", {0}, "TIMES ", {0}, "RGMXXX", {0}, "FACE  FACEMLPLABEL", {
	    0}, "PLANO PLANE ", {0}, "TAPKUL", {0}, "OPTIONGOHOME", {0}, 
	    "BCD   TP    ", {0}, "DISPLY", {0}, "DISTF ", {0}, "5PT   ", {0}, 
	    "NOZ   ", {0}, "MIRRORWEIGHT", {0}, "UNLOAD", {0}, "PNTSONPBS   ",
	     {0}, "PNTVEC", {0}, "REFSYS", {0}, "DOTF  ", {0}, "GMLXXX", {0}, 
	    "XYZ   ", {0}, "DOTTED", {0}, "CLRSRFPEN   ", {0}, "CLRXXX", {0}, 
	    "GEOM  ", {0}, "MDEND ", {0}, "LOW   ", {0}, "PENDWN", {0}, "COM"
	    "BIN", {0}, ".TRUE PENUP ", {0}, "WRTMDI", {0}, "DYNDMP", {0}, 
	    "INCR  ", {0}, "AT    ", {0}, "ATANF ATAN2FATANB ATAN2BATANGLGOT"
	    "O  LOADTL", {0}, "CRSSPL", {0}, "CCLW  ", {0}, "RULED ", {0}, 
	    "POSMAPPOSN  ", {0}, "PS    ", {0}, "POSTN ", {0}, "XAXIS SIGNF "
	    "POSX  POSZ  POSY  YLARGE", {0}, "DITTO ", {0}, "THETAR", {0}, 
	    "MED   ", {0}, "TOOL  TOOLNO", {0}, "DEEP  ", {0}, "MIST  ", {0}, 
	    "REGBRK", {0}, "REGION", {0}, "RANDOM", {0}, "RANGE ", {0}, "REG"
	    "TOLMEDIUM", {0}, "HEAD  ", {0}, "NOPOST", {0}, "NOPS  ", {0}, 
	    "OFF   FUNOFY", {0}, "VECTOR", {0}, "SCRIBE", {0}, "MOTDIR", {0}, 
	    "CHORD ", {0}, "CHDPT SFM   ", {0}, "CONE  ", {0}, "OFFSETXYPLAN",
	     {0}, "PPRINT", {0}, "CONST CONTRLCONTINBLACK ", {0}, "INDEX ", {
	    0}, "DRESS INDIRVINDIRP", {0}, "AAXIS ", {0}, "GOUGCK", {0}, 
	    "APTRANAPTRENMCHFINIFRO  GOUP  BORE  ", {0}, "MCHTOL", {0}, ".GT"
	    "   ", {0}, "SMALL ", {0}, "CFSAVE", {0}, "POINT ", {0}, "ELLIPS", 
	    {0}, "GREEN SAVMDI", {0}, "HEX   ", {0}, "SAVTDI", {0}, "PROBX Y"
	    "ZVIEWPROBY ", {0}, "RESERVRESET ", {0}, "RADIUS", {0}, "LIMIT ", {
	    0}, "ZXVIEWLETTER", {0}, "LIBPRT", {0}, "PITCH PPS   ", {0}, 
	    "SYN   ", {0}, "CHECK ", {0}, "EJECT ", {0}, "FINI  ", {0}, "COO"
	    "LNT", {0}, "CODEL ", {0}, "WCORN ", {0}, ".OR   PLOT  PLOTFT", {0}
	    , "LOCK  LOCKX ", {0}, "THREAD", {0}, "IPM   ", {0}, "YSMALL", {0}
	    , "THRU  NEXT  ", {0}, "SPHERE", {0}, "START ZCOORD", {0}, "UVAL"
	    "  ", {0}, "RETAIN", {0}, "SLOPE ", {0}, "SLOWDNPREFUN", {0}, 
	    "RETR  RETRCT", {0}, "HIGHT HIGH  MAXF  MAXDPMMAXDP MAXIPM", {0}, 
	    "RAPID MAXLNG", {0}, "MAXPTS", {0}, "MAXRPMMAXSTP", {0}, "MAXVEL"
	    "MAXWD ", {0}, "LINCIR", {0}, "NORMALLINEARNORMDSNORMPSLINE  ORIG"
	    "INTRACUTAUXFUNVTLAXS", {0}, "DOWN  ", {0}, "TRANSLTRANS LINTOLTR"
	    "ANTO", {0}, ".FALSETRAV  TRAVED", {0}, "DO    ", {0}, "MOVETO", {
	    0}, "TURN  ", {0}, "TURRET", {0}, "3PT2SL", {0}, "XYROT ", {0}, 
	    "COPY  ", {0}, "PDS   ", {0}, "UP    ", {0}, "LOOPSTLOOPNDBOTH  "
	    "GOLFT ", {0}, "SQRTF ZSURF ", {0}, "GOLOFT", {0}, "GO    ", {0}, 
	    "DUMYA DUMYB ", {0}, "TLLFT ", {0}, "SEQNO ", {0}, "TWOPT ", {0}, 
	    "MULTRDMULTAX", {0}, "ADJUSTTLAXISSAME  TLAXXX", {0}, "SPINDL", {
	    0}, "RPM   ", {0}, "SPIRAL", {0}, "ARSINFARSINB", {0}, "ISTOP ", {
	    0}, "MANUALMACHIN", {0}, "LAG   ", {0}, "MACRO ", {0}, "LARGE ", {
	    0}, "SCURV PIVOT PIVOTZ", {0}, "PERIM ", {0}, "PERPTOJUMPTOSRFVCT"
	    , {0}, "PTNORM", {0}, "AXIS  ", {0}, "YAXIS ", {0}, "ZLARGE", {0},
	     "EXPF  ", {0}, "GOMILL", {0}, "BOUNDS", {0}, "GOBACK", {0}, 
	    "SEG   ", {0}, "POLCON", {0}, "LCONICTHICK ", {0}, "GCLEARREV   ",
	     {0}, "POLYGN", {0}, "CURSEGBREAK ", {0}, "MMPM  ", {0}, "MMPR  ",
	     {0}, "REVERS", {0}, "REVOLVMILL  ", {0}, "CLW   ", {0}, "SWITCH",
	     {0}, "SSPRT ", {0}, "SOLID ", {0}, "LEAD  LEADER", {0}, "CLAMP ",
	     {0}, "BAXIS LAST  ", {0}, "GAPLES", {0}, "ZIGZAG", {0}, "0     "
	    "      1           2           3           4           5         "
	    "  6           7           8           9           0.          1."
	    "          10.         " };


/* Subroutine */ int bdbcdp_(void)
{
    return 0;
} /* bdbcdp_ */

/*     BLOCK DATA PROGRAM FOR BCDPTR */
/*   NAMTBL POINTER FOR .AC. */
/*   NAMTBL POINTER FOR FEDRAT */
/*   NAMTBL POINTER FOR TO */
/*   NAMTBL POINTER FOR DS */
/*   NAMTBL POINTER FOR APTER */
/*   NAMTBL POINTER FOR $21T$1 */
/*   NAMTBL POINTER FOR $$TAB */

/* Subroutine */ int bdnump_(void)
{
    return 0;
} /* bdnump_ */

/*     BLOCK DATA PROGRAM FOR NUMPTR */

/*   NAMTBL POINTER FOR 0 */
/*   NAMTBL POINTER FOR 0. */
/*   NAMTBL POINTER FOR 1 */
/*   NAMTBL POINTER FOR 1. */
/*   NAMTBL POINTER FOR 2 */
/*   NAMTBL POINTER FOR 3 */
/*   NAMTBL POINTER FOR 4 */
/*   NAMTBL POINTER FOR 5 */
/*   NAMTBL POINTER FOR 6 */
/*   NAMTBL POINTER FOR 7 */
/*   NAMTBL POINTER FOR 8 */
/*   NAMTBL POINTER FOR 9 */
/*   NAMTBL POINTER FOR 10. */

/* Subroutine */ int bdsubl_(void)
{
    return 0;
} /* bdsubl_ */

/*     BLOCK DATA PROGRAM FOR SUBLST */

/*   NAMTBL POINTER FOR APT003 */
/*   NAMTBL POINTER FOR APT006 */
/*   NAMTBL POINTER FOR APT007 */
/*   NAMTBL POINTER FOR APT009 */
/*   NAMTBL POINTER FOR APT012 */
/*   NAMTBL POINTER FOR APT011 */
/*   NAMTBL POINTER FOR APT014 */
/*   NAMTBL POINTER FOR APT018 */
/*   NAMTBL POINTER FOR APT019 */
/*   NAMTBL POINTER FOR APT021 */
/*   NAMTBL POINTER FOR APT022 */
/*   NAMTBL POINTER FOR APT049 */
/*   NAMTBL POINTER FOR APT025 */
/*   NAMTBL POINTER FOR APT026 */
/*   NAMTBL POINTER FOR APT027 */
/*   NAMTBL POINTER FOR APT035 */
/*   NAMTBL POINTER FOR APT023 */
/*   NAMTBL POINTER FOR APT024 */
/*   NAMTBL POINTER FOR APT037 */
/*   NAMTBL POINTER FOR APT038 */
/*   NAMTBL POINTER FOR APT035 */
/*   NAMTBL POINTER FOR APT039 */
/*   NAMTBL POINTER FOR APT040 */
/*   NAMTBL POINTER FOR APT044 */
/*   NAMTBL POINTER FOR APT045 */
/*   NAMTBL POINTER FOR APT046 */
/*   NAMTBL POINTER FOR APT105 */
/*   NAMTBL POINTER FOR APT048 */
/*   NAMTBL POINTER FOR APT050 */
/*   NAMTBL POINTER FOR APT051 */
/*   NAMTBL POINTER FOR APT052 */
/*   NAMTBL POINTER FOR APT053 */
/*   NAMTBL POINTER FOR APT054 */
/*   NAMTBL POINTER FOR APT055 */
/*   NAMTBL POINTER FOR APT056 */
/*   NAMTBL POINTER FOR APT057 */
/*   NAMTBL POINTER FOR APT058 */
/*   NAMTBL POINTER FOR APT060 */
/*   NAMTBL POINTER FOR APT062 */
/*   NAMTBL POINTER FOR APT063 */
/*   NAMTBL POINTER FOR APT066 */
/*   NAMTBL POINTER FOR APT067 */
/*   NAMTBL POINTER FOR APT068 */
/*   NAMTBL POINTER FOR ZSURF */
/*   NAMTBL POINTER FOR APT106 */
/*   NAMTBL POINTER FOR APT005 */
/*   NAMTBL POINTER FOR APT008 */
/*   NAMTBL POINTER FOR APT010 */
/*   NAMTBL POINTER FOR APT001 */
/*   NAMTBL POINTER FOR APT015 */
/*   NAMTBL POINTER FOR APT016 */
/*   NAMTBL POINTER FOR APT017 */
/*   NAMTBL POINTER FOR APT020 */
/*   NAMTBL POINTER FOR APT028 */
/*   NAMTBL POINTER FOR APT029 */
/*   NAMTBL POINTER FOR APT030 */
/*   NAMTBL POINTER FOR APT031 */
/*   NAMTBL POINTER FOR APT032 */
/*   NAMTBL POINTER FOR APT033 */
/*   NAMTBL POINTER FOR APT036 */
/*   NAMTBL POINTER FOR APT010 */
/*   NAMTBL POINTER FOR APT047 */
/*   NAMTBL POINTER FOR APT064 */
/*   NAMTBL POINTER FOR APT065 */
/*   NAMTBL POINTER FOR APT004 */
/*   NAMTBL POINTER FOR APT036 */
/*   NAMTBL POINTER FOR APT088 */
/*   NAMTBL POINTER FOR APT094 */
/*   NAMTBL POINTER FOR APT061 */
/*   NAMTBL POINTER FOR APT012 */
/*   NAMTBL POINTER FOR APT061 */
/*   NAMTBL POINTER FOR APT087 */
/*   NAMTBL POINTER FOR APT100 */
/*   NAMTBL POINTER FOR UNDEF */
/*   NAMTBL POINTER FOR APT041 */
/*   NAMTBL POINTER FOR APT043 */
/*   NAMTBL POINTER FOR APT042 */
/*   NAMTBL POINTER FOR APT069 */
/*   NAMTBL POINTER FOR APT070 */
/*   NAMTBL POINTER FOR APT071 */
/*   NAMTBL POINTER FOR APT072 */
/*   NAMTBL POINTER FOR DEFEXT */
/*   NAMTBL POINTER FOR APT074 */
/*   NAMTBL POINTER FOR APT034 */
/*   NAMTBL POINTER FOR APT104 */
/*   NAMTBL POINTER FOR APT102 */
/*   NAMTBL POINTER FOR APT103 */
/*   NAMTBL POINTER FOR APT107 */
/*   NAMTBL POINTER FOR APT013 */
/*   NAMTBL POINTER FOR APT108 */
/*   NAMTBL POINTER FOR APT109 */
/*   NAMTBL POINTER FOR APT110 */
/*   NAMTBL POINTER FOR APT101 */
/*   NAMTBL POINTER FOR NDTEST */
/*   NAMTBL POINTER FOR COMP3D */
/*   NAMTBL POINTER FOR TLON */
/*   NAMTBL POINTER FOR GOTOPN */
/*   NAMTBL POINTER FOR APT090 */
/*   NAMTBL POINTER FOR APT105 */
/*   NAMTBL POINTER FOR APT106 */
/*   NAMTBL POINTER FOR TRANSF */
/*   NAMTBL POINTER FOR LOGIF */
/*   NAMTBL POINTER FOR APT081 */
/*   NAMTBL POINTER FOR APT083 */
/*   NAMTBL POINTER FOR APT078 */
/*   NAMTBL POINTER FOR APT077 */
/*   NAMTBL POINTER FOR APT079 */
/*   NAMTBL POINTER FOR APT085 */
/*   NAMTBL POINTER FOR APT200 */
/*   NAMTBL POINTER FOR APT201 */
/*   NAMTBL POINTER FOR APT295 */
/*   NAMTBL POINTER FOR APT298 */
/*   NAMTBL POINTER FOR APT299 */
/*   NAMTBL POINTER FOR ERROR */
/*   NAMTBL POINTER FOR PSIS */
/*   NAMTBL POINTER FOR REFSYS */
/*   NAMTBL POINTER FOR TLAXIS */

/* Subroutine */ int bdname_(void)
{
    return 0;
} /* bdname_ */

/*     BLOCK DATA PROGRAM FOR NAMETB */
/*       gfortran chokes on initializations like this- */
/*       maybe because it thinks you want to define it */
/*       twice? */
/*      DATA NAMTBL/ 3000*0/ */
/*      DATA CNAMTB/ 3000*' '/ */
/*      DATA CNUMTB/ 3000*' '/ */
/*      first entry is implied by the commented initialization */
/*          NAMTBL ENTRY FOR 0 */
/*          NAMTBL ENTRY FOR 1 */
/*          NAMTBL ENTRY FOR 2 */
/*          NAMTBL ENTRY FOR 3 */
/*          NAMTBL ENTRY FOR 4 */
/*          NAMTBL ENTRY FOR 5 */
/*          NAMTBL ENTRY FOR 6 */
/*          NAMTBL ENTRY FOR 7 */
/*          NAMTBL ENTRY FOR 8 */
/*          NAMTBL ENTRY FOR 9 */
/*          NAMTBL ENTRY FOR = */
/*          NAMTBL ENTRY FOR ' */
/*          NAMTBL ENTRY FOR + */
/*          NAMTBL ENTRY FOR A */
/*          NAMTBL ENTRY FOR B */
/*          NAMTBL ENTRY FOR C */
/*          NAMTBL ENTRY FOR D */
/*          NAMTBL ENTRY FOR E */
/*          NAMTBL ENTRY FOR F */
/*          NAMTBL ENTRY FOR G */
/*          NAMTBL ENTRY FOR H */
/*          NAMTBL ENTRY FOR I */
/*          NAMTBL ENTRY FOR . */
/*          NAMTBL ENTRY FOR ) */
/*          NAMTBL ENTRY FOR - */
/*          NAMTBL ENTRY FOR J */
/*          NAMTBL ENTRY FOR K */
/*          NAMTBL ENTRY FOR L */
/*          NAMTBL ENTRY FOR M */
/*          NAMTBL ENTRY FOR N */
/*          NAMTBL ENTRY FOR O */
/*          NAMTBL ENTRY FOR P */
/*          NAMTBL ENTRY FOR Q */
/*          NAMTBL ENTRY FOR R */
/*          NAMTBL ENTRY FOR $ */
/*          NAMTBL ENTRY FOR * */
/*          NAMTBL ENTRY FOR */
/*          NAMTBL ENTRY FOR / */
/*          NAMTBL ENTRY FOR S */
/*          NAMTBL ENTRY FOR T */
/*          NAMTBL ENTRY FOR U */
/*          NAMTBL ENTRY FOR V */
/*          NAMTBL ENTRY FOR W */
/*          NAMTBL ENTRY FOR X */
/*          NAMTBL ENTRY FOR Y */
/*          NAMTBL ENTRY FOR Z */
/*          NAMTBL ENTRY FOR , */
/*          NAMTBL ENTRY FOR ( */
/*          NAMTBL ENTRY FOR LTERM */
/*          NAMTBL ENTRY FOR RTERM */
/*          NAMTBL ENTRY FOR MCLTRM */
/*          NAMTBL ENTRY FOR DBLAST */
/*          NAMTBL ENTRY FOR DOT */
/*          NAMTBL ENTRY FOR KREUZ */
/*          NAMTBL ENTRY FOR CONAST */
/*          NAMTBL ENTRY FOR UNDEF */
/*          NAMTBL ENTRY FOR APT001 */
/*          NAMTBL ENTRY FOR APT003 */
/*          NAMTBL ENTRY FOR APT004 */
/*          NAMTBL ENTRY FOR APT005 */
/*          NAMTBL ENTRY FOR APT006 */
/*          NAMTBL ENTRY FOR APT007 */
/*          NAMTBL ENTRY FOR APT008 */
/*          NAMTBL ENTRY FOR APT009 */
/*          NAMTBL ENTRY FOR APT010 */
/*          NAMTBL ENTRY FOR APT011 */
/*          NAMTBL ENTRY FOR APT012 */
/*          NAMTBL ENTRY FOR APT014 */
/*          NAMTBL ENTRY FOR APT015 */
/*          NAMTBL ENTRY FOR APT016 */
/*          NAMTBL ENTRY FOR APT017 */
/*          NAMTBL ENTRY FOR APT018 */
/*          NAMTBL ENTRY FOR APT019 */
/*          NAMTBL ENTRY FOR APT020 */
/*          NAMTBL ENTRY FOR APT021 */
/*          NAMTBL ENTRY FOR APT022 */
/*          NAMTBL ENTRY FOR APT023 */
/*          NAMTBL ENTRY FOR APT024 */
/*          NAMTBL ENTRY FOR APT025 */
/*          NAMTBL ENTRY FOR APT026 */
/*          NAMTBL ENTRY FOR APT027 */
/*          NAMTBL ENTRY FOR APT028 */
/*          NAMTBL ENTRY FOR APT029 */
/*          NAMTBL ENTRY FOR APT030 */
/*          NAMTBL ENTRY FOR APT031 */
/*          NAMTBL ENTRY FOR APT032 */
/*          NAMTBL ENTRY FOR APT033 */
/*          NAMTBL ENTRY FOR APT035 */
/*          NAMTBL ENTRY FOR APT036 */
/*          NAMTBL ENTRY FOR APT037 */
/*          NAMTBL ENTRY FOR APT038 */
/*          NAMTBL ENTRY FOR APT039 */
/*          NAMTBL ENTRY FOR APT040 */
/*          NAMTBL ENTRY FOR APT044 */
/*          NAMTBL ENTRY FOR APT045 */
/*          NAMTBL ENTRY FOR APT046 */
/*          NAMTBL ENTRY FOR APT047 */
/*          NAMTBL ENTRY FOR APT048 */
/*          NAMTBL ENTRY FOR APT049 */
/*          NAMTBL ENTRY FOR APT050 */
/*          NAMTBL ENTRY FOR APT051 */
/*          NAMTBL ENTRY FOR APT052 */
/*          NAMTBL ENTRY FOR APT053 */
/*          NAMTBL ENTRY FOR APT054 */
/*          NAMTBL ENTRY FOR APT055 */
/*          NAMTBL ENTRY FOR APT056 */
/*          NAMTBL ENTRY FOR APT057 */
/*          NAMTBL ENTRY FOR APT058 */
/*          NAMTBL ENTRY FOR APT060 */
/*          NAMTBL ENTRY FOR APT061 */
/*          NAMTBL ENTRY FOR APT062 */
/*          NAMTBL ENTRY FOR APT063 */
/*          NAMTBL ENTRY FOR APT064 */
/*          NAMTBL ENTRY FOR APT065 */
/*          NAMTBL ENTRY FOR APT066 */
/*          NAMTBL ENTRY FOR APT067 */
/*          NAMTBL ENTRY FOR APT068 */
/*          NAMTBL ENTRY FOR APT073 */
/*          NAMTBL ENTRY FOR APT075 */
/*          NAMTBL ENTRY FOR APT077 */
/*          NAMTBL ENTRY FOR APT078 */
/*          NAMTBL ENTRY FOR APT079 */
/*          NAMTBL ENTRY FOR APT081 */
/*          NAMTBL ENTRY FOR APT083 */
/*          NAMTBL ENTRY FOR APT085 */
/*          NAMTBL ENTRY FOR APT087 */
/*          NAMTBL ENTRY FOR APT088 */
/*          NAMTBL ENTRY FOR APT090 */
/*          NAMTBL ENTRY FOR APT092 */
/*          NAMTBL ENTRY FOR APT093 */
/*          NAMTBL ENTRY FOR APT094 */
/*          NAMTBL ENTRY FOR APT100 */
/*          NAMTBL ENTRY FOR APT200 */
/*          NAMTBL ENTRY FOR APT201 */
/*          NAMTBL ENTRY FOR APT298 */
/*          NAMTBL ENTRY FOR APT299 */
/*          NAMTBL ENTRY FOR APT041 */
/*          NAMTBL ENTRY FOR APT043 */
/*          NAMTBL ENTRY FOR APT295 */
/*          NAMTBL ENTRY FOR APT042 */
/*          NAMTBL ENTRY FOR APT069 */
/*          NAMTBL ENTRY FOR APT070 */
/*          NAMTBL ENTRY FOR APT071 */
/*          NAMTBL ENTRY FOR APT072 */
/*          NAMTBL ENTRY FOR APT074 */
/*          NAMTBL ENTRY FOR APT034 */
/*          NAMTBL ENTRY FOR DEFEXT */
/*          NAMTBL ENTRY FOR APT101 */
/*          NAMTBL ENTRY FOR NDTEST */
/*          NAMTBL ENTRY FOR COMP3D */
/*          NAMTBL ENTRY FOR TLON */
/*          NAMTBL ENTRY FOR GOTOPN */
/*          NAMTBL ENTRY FOR APT105 */
/*          NAMTBL ENTRY FOR APT106 */
/*          NAMTBL ENTRY FOR TRANSF */
/*          NAMTBL ENTRY FOR APT104 */
/*          NAMTBL ENTRY FOR APT102 */
/*          NAMTBL ENTRY FOR APT103 */
/*          NAMTBL ENTRY FOR APT107 */
/*          NAMTBL ENTRY FOR APT013 */
/*          NAMTBL ENTRY FOR APT108 */
/*          NAMTBL ENTRY FOR APT109 */
/*          NAMTBL ENTRY FOR APT110 */
/*          NAMTBL ENTRY FOR LOGIF */
/*          NAMTBL ENTRY FOR .AC. */
/*          NAMTBL ENTRY FOR APTER */
/*          NAMTBL ENTRY FOR $21T$1 */
/*          NAMTBL ENTRY FOR $$TAB */
/*          NAMTBL ENTRY FOR INSERT */
/*          NAMTBL ENTRY FOR CORNFD */
/*          NAMTBL ENTRY FOR PTONLY */
/*          NAMTBL ENTRY FOR DRILL */
/*          NAMTBL ENTRY FOR OMIT */
/*          NAMTBL ENTRY FOR TMARK */
/*          NAMTBL ENTRY FOR FWD */
/*          NAMTBL ENTRY FOR SUBSCR */
/*          NAMTBL ENTRY FOR GOCLER */
/*          NAMTBL ENTRY FOR TLNDON */
/*          NAMTBL ENTRY FOR NPS */
/*          NAMTBL ENTRY FOR SMESH */
/*          NAMTBL ENTRY FOR CYLNDR */
/*          NAMTBL ENTRY FOR GRID */
/*          NAMTBL ENTRY FOR STOP */
/*          NAMTBL ENTRY FOR AWAY */
/*          NAMTBL ENTRY FOR SADDLE */
/*          NAMTBL ENTRY FOR 2DCALC */
/*          NAMTBL ENTRY FOR UCONST */
/*          NAMTBL ENTRY FOR REWIND */
/*          NAMTBL ENTRY FOR PVAL */
/*          NAMTBL ENTRY FOR CIRCUL */
/*          NAMTBL ENTRY FOR CIRCLE */
/*          NAMTBL ENTRY FOR RTHETA */
/*          NAMTBL ENTRY FOR CIRLIN */
/*          NAMTBL ENTRY FOR READ */
/*          NAMTBL ENTRY FOR RELTOL */
/*          NAMTBL ENTRY FOR REAL */
/*          NAMTBL ENTRY FOR REAM */
/*          NAMTBL ENTRY FOR AVCTRL */
/*          NAMTBL ENTRY FOR AVCXXX */
/*          NAMTBL ENTRY FOR OVPLOT */
/*          NAMTBL ENTRY FOR REAR */
/*          NAMTBL ENTRY FOR PUNCH */
/*          NAMTBL ENTRY FOR CENTER */
/*          NAMTBL ENTRY FOR DDLIM */
/*          NAMTBL ENTRY FOR .EQ */
/*          NAMTBL ENTRY FOR XCOORD */
/*          NAMTBL ENTRY FOR SVAL */
/*          NAMTBL ENTRY FOR COSB */
/*          NAMTBL ENTRY FOR COSF */
/*          NAMTBL ENTRY FOR COSHF */
/*          NAMTBL ENTRY FOR SCALE */
/*          NAMTBL ENTRY FOR SCALAR */
/*          NAMTBL ENTRY FOR INTERC */
/*          NAMTBL ENTRY FOR INTF */
/*          NAMTBL ENTRY FOR INTENS */
/*          NAMTBL ENTRY FOR SCALOP */
/*          NAMTBL ENTRY FOR BACK */
/*          NAMTBL ENTRY FOR CS */
/*          NAMTBL ENTRY FOR INTCOD */
/*          NAMTBL ENTRY FOR .LE */
/*          NAMTBL ENTRY FOR INTOF */
/*          NAMTBL ENTRY FOR INTOL */
/*          NAMTBL ENTRY FOR INTSEC */
/*          NAMTBL ENTRY FOR TITLES */
/*          NAMTBL ENTRY FOR LOG10F */
/*          NAMTBL ENTRY FOR PPLOT */
/*          NAMTBL ENTRY FOR INIT */
/*          NAMTBL ENTRY FOR ZSMALL */
/*          NAMTBL ENTRY FOR LOGF */
/*          NAMTBL ENTRY FOR CUT */
/*          NAMTBL ENTRY FOR IF */
/*          NAMTBL ENTRY FOR GODLTA */
/*          NAMTBL ENTRY FOR GODOWN */
/*          NAMTBL ENTRY FOR OPPLOT */
/*          NAMTBL ENTRY FOR TLOFPS */
/*          NAMTBL ENTRY FOR HYPERB */
/*          NAMTBL ENTRY FOR VVAL */
/*          NAMTBL ENTRY FOR TA */
/*          NAMTBL ENTRY FOR SETANG */
/*          NAMTBL ENTRY FOR TLON */
/*          NAMTBL ENTRY FOR TLONPS */
/*          NAMTBL ENTRY FOR OPEN */
/*          NAMTBL ENTRY FOR CUTANG */
/*          NAMTBL ENTRY FOR CUTCOM */
/*          NAMTBL ENTRY FOR SETOOL */
/*          NAMTBL ENTRY FOR LNTHF */
/*          NAMTBL ENTRY FOR POCKET */
/*          NAMTBL ENTRY FOR UVPDS */
/*          NAMTBL ENTRY FOR CUTTER */
/*          NAMTBL ENTRY FOR WITH */
/*          NAMTBL ENTRY FOR SPLINE */
/*          NAMTBL ENTRY FOR STEP */
/*          NAMTBL ENTRY FOR STEPOV */
/*          NAMTBL ENTRY FOR UVPPS */
/*          NAMTBL ENTRY FOR NDS */
/*          NAMTBL ENTRY FOR DARK */
/*          NAMTBL ENTRY FOR MINF */
/*          NAMTBL ENTRY FOR YZPLAN */
/*          NAMTBL ENTRY FOR SPATF */
/*          NAMTBL ENTRY FOR AVOID */
/*          NAMTBL ENTRY FOR REMARK */
/*          NAMTBL ENTRY FOR PRINT */
/*          NAMTBL ENTRY FOR MINUS */
/*          NAMTBL ENTRY FOR GFTXXX */
/*          NAMTBL ENTRY FOR DSTAN */
/*          NAMTBL ENTRY FOR RAIL */
/*          NAMTBL ENTRY FOR 4PT1SL */
/*          NAMTBL ENTRY FOR ANGLF */
/*          NAMTBL ENTRY FOR ANGLB */
/*          NAMTBL ENTRY FOR ANGLE */
/*          NAMTBL ENTRY FOR LIGHT */
/*          NAMTBL ENTRY FOR ERROR */
/*          NAMTBL ENTRY FOR LENGTH */
/*          NAMTBL ENTRY FOR CHUCK */
/*          NAMTBL ENTRY FOR ZXPLAN */
/*          NAMTBL ENTRY FOR MDWRIT */
/*          NAMTBL ENTRY FOR COTANF */
/*          NAMTBL ENTRY FOR COTANB */
/*          NAMTBL ENTRY FOR HOLDER */
/*          NAMTBL ENTRY FOR XYVIEW */
/*          NAMTBL ENTRY FOR MODE */
/*          NAMTBL ENTRY FOR MODF */
/*          NAMTBL ENTRY FOR PICKFD */
/*          NAMTBL ENTRY FOR PICKUP */
/*          NAMTBL ENTRY FOR MODIFY */
/*          NAMTBL ENTRY FOR .AND */
/*          NAMTBL ENTRY FOR TPI */
/*          NAMTBL ENTRY FOR FEDRAT */
/*          NAMTBL ENTRY FOR CROSS */
/*          NAMTBL ENTRY FOR TABCYL */
/*          NAMTBL ENTRY FOR SINB */
/*          NAMTBL ENTRY FOR SINF */
/*          NAMTBL ENTRY FOR SINHF */
/*          NAMTBL ENTRY FOR TABPRT */
/*          NAMTBL ENTRY FOR IPR */
/*          NAMTBL ENTRY FOR TLPROJ */
/*          NAMTBL ENTRY FOR GCONIC */
/*          NAMTBL ENTRY FOR CYCLE */
/*          NAMTBL ENTRY FOR DELAY */
/*          NAMTBL ENTRY FOR DELETE */
/*          NAMTBL ENTRY FOR SAFETY */
/*          NAMTBL ENTRY FOR NEGX */
/*          NAMTBL ENTRY FOR NEGY */
/*          NAMTBL ENTRY FOR NEGZ */
/*          NAMTBL ENTRY FOR DASH */
/*          NAMTBL ENTRY FOR NOW */
/*          NAMTBL ENTRY FOR RIGHT */
/*          NAMTBL ENTRY FOR XLARGE */
/*          NAMTBL ENTRY FOR AVPRT */
/*          NAMTBL ENTRY FOR FROM */
/*          NAMTBL ENTRY FOR FRONT */
/*          NAMTBL ENTRY FOR NDTEST */
/*          NAMTBL ENTRY FOR UNIT */
/*          NAMTBL ENTRY FOR UNITS */
/*          NAMTBL ENTRY FOR OUT */
/*          NAMTBL ENTRY FOR NOLIST */
/*          NAMTBL ENTRY FOR END */
/*          NAMTBL ENTRY FOR MAGTAP */
/*          NAMTBL ENTRY FOR CALL */
/*          NAMTBL ENTRY FOR TRFORM */
/*          NAMTBL ENTRY FOR LISTON */
/*          NAMTBL ENTRY FOR TYPE */
/*          NAMTBL ENTRY FOR CLDATF */
/*          NAMTBL ENTRY FOR CLDATA */
/*          NAMTBL ENTRY FOR CLDAT */
/*          NAMTBL ENTRY FOR LPRINT */
/*          NAMTBL ENTRY FOR ENDARC */
/*          NAMTBL ENTRY FOR ENDMDI */
/*          NAMTBL ENTRY FOR CHKSRF */
/*          NAMTBL ENTRY FOR OBTAIN */
/*          NAMTBL ENTRY FOR ZAXIS */
/*          NAMTBL ENTRY FOR OUTTOL */
/*          NAMTBL ENTRY FOR INVERS */
/*          NAMTBL ENTRY FOR COUPLE */
/*          NAMTBL ENTRY FOR PARAB */
/*          NAMTBL ENTRY FOR PARAM */
/*          NAMTBL ENTRY FOR PARLEL */
/*          NAMTBL ENTRY FOR PARMF */
/*          NAMTBL ENTRY FOR DRAFT */
/*          NAMTBL ENTRY FOR ALL */
/*          NAMTBL ENTRY FOR PARSRF */
/*          NAMTBL ENTRY FOR PART */
/*          NAMTBL ENTRY FOR FEED */
/*          NAMTBL ENTRY FOR PARTNO */
/*          NAMTBL ENTRY FOR PLUNGE */
/*          NAMTBL ENTRY FOR DRAWLI */
/*          NAMTBL ENTRY FOR PLUS */
/*          NAMTBL ENTRY FOR NUMF */
/*          NAMTBL ENTRY FOR TERMAC */
/*          NAMTBL ENTRY FOR NUMPTS */
/*          NAMTBL ENTRY FOR PSTAN */
/*          NAMTBL ENTRY FOR TANB */
/*          NAMTBL ENTRY FOR FLOOD */
/*          NAMTBL ENTRY FOR TANF */
/*          NAMTBL ENTRY FOR TANHF */
/*          NAMTBL ENTRY FOR FLOW */
/*          NAMTBL ENTRY FOR TANON */
/*          NAMTBL ENTRY FOR TANSPL */
/*          NAMTBL ENTRY FOR TANTO */
/*          NAMTBL ENTRY FOR GOFWD */
/*          NAMTBL ENTRY FOR PSIS */
/*          NAMTBL ENTRY FOR SIDE */
/*          NAMTBL ENTRY FOR .GE */
/*          NAMTBL ENTRY FOR FOURPT */
/*          NAMTBL ENTRY FOR RED */
/*          NAMTBL ENTRY FOR TOLER */
/*          NAMTBL ENTRY FOR NOX */
/*          NAMTBL ENTRY FOR YZROT */
/*          NAMTBL ENTRY FOR TO */
/*          NAMTBL ENTRY FOR DEBUGG */
/*          NAMTBL ENTRY FOR CAM */
/*          NAMTBL ENTRY FOR SSTEST */
/*          NAMTBL ENTRY FOR .NOT */
/*          NAMTBL ENTRY FOR CAXIS */
/*          NAMTBL ENTRY FOR ANTSPI */
/*          NAMTBL ENTRY FOR LITE */
/*          NAMTBL ENTRY FOR CAMERA */
/*          NAMTBL ENTRY FOR NOMORE */
/*          NAMTBL ENTRY FOR BINARY */
/*          NAMTBL ENTRY FOR NOBND */
/*          NAMTBL ENTRY FOR CLEARS */
/*          NAMTBL ENTRY FOR CLEARP */
/*          NAMTBL ENTRY FOR CLPRNT */
/*          NAMTBL ENTRY FOR BINORM */
/*          NAMTBL ENTRY FOR AIR */
/*          NAMTBL ENTRY FOR ABSF */
/*          NAMTBL ENTRY FOR ROTABL */
/*          NAMTBL ENTRY FOR ZXROT */
/*          NAMTBL ENTRY FOR ROTHED */
/*          NAMTBL ENTRY FOR ROTREF */
/*          NAMTBL ENTRY FOR SCON */
/*          NAMTBL ENTRY FOR ZERO */
/*          NAMTBL ENTRY FOR QADRIC */
/*          NAMTBL ENTRY FOR PTSLOP */
/*          NAMTBL ENTRY FOR OBJECT */
/*          NAMTBL ENTRY FOR DNTCUT */
/*          NAMTBL ENTRY FOR PAST */
/*          NAMTBL ENTRY FOR PPOPTN */
/*          NAMTBL ENTRY FOR IN */
/*          NAMTBL ENTRY FOR GORGT */
/*          NAMTBL ENTRY FOR OPSKIP */
/*          NAMTBL ENTRY FOR 3DCALC */
/*          NAMTBL ENTRY FOR TLRGT */
/*          NAMTBL ENTRY FOR SMIL */
/*          NAMTBL ENTRY FOR OPSTOP */
/*          NAMTBL ENTRY FOR NIXIE */
/*          NAMTBL ENTRY FOR VCONST */
/*          NAMTBL ENTRY FOR SELCTL */
/*          NAMTBL ENTRY FOR ASLOPE */
/*          NAMTBL ENTRY FOR .NE */
/*          NAMTBL ENTRY FOR ARC */
/*          NAMTBL ENTRY FOR NOY */
/*          NAMTBL ENTRY FOR DECR */
/*          NAMTBL ENTRY FOR XSMALL */
/*          NAMTBL ENTRY FOR SSURF */
/*          NAMTBL ENTRY FOR MATRIX */
/*          NAMTBL ENTRY FOR YCOORD */
/*          NAMTBL ENTRY FOR ARCOSF */
/*          NAMTBL ENTRY FOR ARCOSB */
/*          NAMTBL ENTRY FOR TV */
/*          NAMTBL ENTRY FOR TVAL */
/*          NAMTBL ENTRY FOR ARCSLP */
/*          NAMTBL ENTRY FOR MAIN */
/*          NAMTBL ENTRY FOR CANF */
/*          NAMTBL ENTRY FOR DWELL */
/*          NAMTBL ENTRY FOR CANON */
/*          NAMTBL ENTRY FOR RLDSRF */
/*          NAMTBL ENTRY FOR DS */
/*          NAMTBL ENTRY FOR NOCLRP */
/*          NAMTBL ENTRY FOR FULL */
/*          NAMTBL ENTRY FOR AUTO */
/*          NAMTBL ENTRY FOR AUTOPS */
/*          NAMTBL ENTRY FOR GENCUR */
/*          NAMTBL ENTRY FOR ON */
/*          NAMTBL ENTRY FOR TUNEUP */
/*          NAMTBL ENTRY FOR LEFT */
/*          NAMTBL ENTRY FOR .LT */
/*          NAMTBL ENTRY FOR BLUE */
/*          NAMTBL ENTRY FOR PATCH */
/*          NAMTBL ENTRY FOR PATERN */
/*          NAMTBL ENTRY FOR PATH */
/*          NAMTBL ENTRY FOR COLLET */
/*          NAMTBL ENTRY FOR TAP */
/*          NAMTBL ENTRY FOR ULOCKX */
/*          NAMTBL ENTRY FOR TIMES */
/*          NAMTBL ENTRY FOR RGMXXX */
/*          NAMTBL ENTRY FOR FACE */
/*          NAMTBL ENTRY FOR FACEML */
/*          NAMTBL ENTRY FOR PLABEL */
/*          NAMTBL ENTRY FOR PLANO */
/*          NAMTBL ENTRY FOR PLANE */
/*          NAMTBL ENTRY FOR TAPKUL */
/*          NAMTBL ENTRY FOR OPTION */
/*          NAMTBL ENTRY FOR GOHOME */
/*          NAMTBL ENTRY FOR BCD */
/*          NAMTBL ENTRY FOR TP */
/*          NAMTBL ENTRY FOR DISPLY */
/*          NAMTBL ENTRY FOR DISTF */
/*          NAMTBL ENTRY FOR 5PT */
/*          NAMTBL ENTRY FOR NOZ */
/*          NAMTBL ENTRY FOR MIRROR */
/*          NAMTBL ENTRY FOR WEIGHT */
/*          NAMTBL ENTRY FOR UNLOAD */
/*          NAMTBL ENTRY FOR PNTSON */
/*          NAMTBL ENTRY FOR PBS */
/*          NAMTBL ENTRY FOR PNTVEC */
/*          NAMTBL ENTRY FOR REFSYS */
/*          NAMTBL ENTRY FOR DOTF */
/*          NAMTBL ENTRY FOR GMLXXX */
/*          NAMTBL ENTRY FOR XYZ */
/*          NAMTBL ENTRY FOR DOTTED */
/*          NAMTBL ENTRY FOR CLRSRF */
/*          NAMTBL ENTRY FOR PEN */
/*          NAMTBL ENTRY FOR CLRXXX */
/*          NAMTBL ENTRY FOR GEOM */
/*          NAMTBL ENTRY FOR MDEND */
/*          NAMTBL ENTRY FOR LOW */
/*          NAMTBL ENTRY FOR PENDWN */
/*          NAMTBL ENTRY FOR COMBIN */
/*          NAMTBL ENTRY FOR .TRUE */
/*          NAMTBL ENTRY FOR PENUP */
/*          NAMTBL ENTRY FOR WRTMDI */
/*          NAMTBL ENTRY FOR DYNDMP */
/*          NAMTBL ENTRY FOR INCR */
/*          NAMTBL ENTRY FOR AT */
/*          NAMTBL ENTRY FOR ATANF */
/*          NAMTBL ENTRY FOR ATAN2F */
/*          NAMTBL ENTRY FOR ATANB */
/*          NAMTBL ENTRY FOR ATAN2B */
/*          NAMTBL ENTRY FOR ATANGL */
/*          NAMTBL ENTRY FOR GOTO */
/*          NAMTBL ENTRY FOR LOADTL */
/*          NAMTBL ENTRY FOR CRSSPL */
/*          NAMTBL ENTRY FOR CCLW */
/*          NAMTBL ENTRY FOR RULED */
/*          NAMTBL ENTRY FOR POSMAP */
/*          NAMTBL ENTRY FOR POSN */
/*          NAMTBL ENTRY FOR PS */
/*          NAMTBL ENTRY FOR POSTN */
/*          NAMTBL ENTRY FOR XAXIS */
/*          NAMTBL ENTRY FOR SIGNF */
/*          NAMTBL ENTRY FOR POSX */
/*          NAMTBL ENTRY FOR POSZ */
/*          NAMTBL ENTRY FOR POSY */
/*          NAMTBL ENTRY FOR YLARGE */
/*          NAMTBL ENTRY FOR DITTO */
/*          NAMTBL ENTRY FOR THETAR */
/*          NAMTBL ENTRY FOR MED */
/*          NAMTBL ENTRY FOR TOOL */
/*          NAMTBL ENTRY FOR TOOLNO */
/*          NAMTBL ENTRY FOR DEEP */
/*          NAMTBL ENTRY FOR MIST */
/*          NAMTBL ENTRY FOR REGBRK */
/*          NAMTBL ENTRY FOR REGION */
/*          NAMTBL ENTRY FOR RANDOM */
/*          NAMTBL ENTRY FOR RANGE */
/*          NAMTBL ENTRY FOR REGTOL */
/*          NAMTBL ENTRY FOR MEDIUM */
/*          NAMTBL ENTRY FOR HEAD */
/*          NAMTBL ENTRY FOR NOPOST */
/*          NAMTBL ENTRY FOR NOPS */
/*          NAMTBL ENTRY FOR OFF */
/*          NAMTBL ENTRY FOR FUNOFY */
/*          NAMTBL ENTRY FOR VECTOR */
/*          NAMTBL ENTRY FOR SCRIBE */
/*          NAMTBL ENTRY FOR MOTDIR */
/*          NAMTBL ENTRY FOR CHORD */
/*          NAMTBL ENTRY FOR CHDPT */
/*          NAMTBL ENTRY FOR SFM */
/*          NAMTBL ENTRY FOR CONE */
/*          NAMTBL ENTRY FOR OFFSET */
/*          NAMTBL ENTRY FOR XYPLAN */
/*          NAMTBL ENTRY FOR PPRINT */
/*          NAMTBL ENTRY FOR CONST */
/*          NAMTBL ENTRY FOR CONTRL */
/*          NAMTBL ENTRY FOR CONTIN */
/*          NAMTBL ENTRY FOR BLACK */
/*          NAMTBL ENTRY FOR INDEX */
/*          NAMTBL ENTRY FOR DRESS */
/*          NAMTBL ENTRY FOR INDIRV */
/*          NAMTBL ENTRY FOR INDIRP */
/*          NAMTBL ENTRY FOR AAXIS */
/*          NAMTBL ENTRY FOR GOUGCK */
/*          NAMTBL ENTRY FOR APTRAN */
/*          NAMTBL ENTRY FOR APTREN */
/*          NAMTBL ENTRY FOR MCHFIN */
/*          NAMTBL ENTRY FOR IFRO */
/*          NAMTBL ENTRY FOR GOUP */
/*          NAMTBL ENTRY FOR BORE */
/*          NAMTBL ENTRY FOR MCHTOL */
/*          NAMTBL ENTRY FOR .GT */
/*          NAMTBL ENTRY FOR SMALL */
/*          NAMTBL ENTRY FOR CFSAVE */
/*          NAMTBL ENTRY FOR POINT */
/*          NAMTBL ENTRY FOR ELLIPS */
/*          NAMTBL ENTRY FOR GREEN */
/*          NAMTBL ENTRY FOR SAVMDI */
/*          NAMTBL ENTRY FOR HEX */
/*          NAMTBL ENTRY FOR SAVTDI */
/*          NAMTBL ENTRY FOR PROBX */
/*          NAMTBL ENTRY FOR YZVIEW */
/*          NAMTBL ENTRY FOR PROBY */
/*          NAMTBL ENTRY FOR RESERV */
/*          NAMTBL ENTRY FOR RESET */
/*          NAMTBL ENTRY FOR RADIUS */
/*          NAMTBL ENTRY FOR LIMIT */
/*          NAMTBL ENTRY FOR ZXVIEW */
/*          NAMTBL ENTRY FOR LETTER */
/*          NAMTBL ENTRY FOR LIBPRT */
/*          NAMTBL ENTRY FOR PITCH */
/*          NAMTBL ENTRY FOR PPS */
/*          NAMTBL ENTRY FOR SYN */
/*          NAMTBL ENTRY FOR CHECK */
/*          NAMTBL ENTRY FOR EJECT */
/*          NAMTBL ENTRY FOR FINI */
/*          NAMTBL ENTRY FOR COOLNT */
/*          NAMTBL ENTRY FOR CODEL */
/*          NAMTBL ENTRY FOR WCORN */
/*          NAMTBL ENTRY FOR .OR */
/*          NAMTBL ENTRY FOR PLOT */
/*          NAMTBL ENTRY FOR PLOTFT */
/*          NAMTBL ENTRY FOR LOCK */
/*          NAMTBL ENTRY FOR LOCKX */
/*          NAMTBL ENTRY FOR THREAD */
/*          NAMTBL ENTRY FOR IPM */
/*          NAMTBL ENTRY FOR YSMALL */
/*          NAMTBL ENTRY FOR THRU */
/*          NAMTBL ENTRY FOR NEXT */
/*          NAMTBL ENTRY FOR SPHERE */
/*          NAMTBL ENTRY FOR START */
/*          NAMTBL ENTRY FOR ZCOORD */
/*          NAMTBL ENTRY FOR UVAL */
/*          NAMTBL ENTRY FOR RETAIN */
/*          NAMTBL ENTRY FOR SLOPE */
/*          NAMTBL ENTRY FOR SLOWDN */
/*          NAMTBL ENTRY FOR PREFUN */
/*          NAMTBL ENTRY FOR RETR */
/*          NAMTBL ENTRY FOR RETRCT */
/*          NAMTBL ENTRY FOR HIGHT */
/*          NAMTBL ENTRY FOR HIGH */
/*          NAMTBL ENTRY FOR MAXF */
/*          NAMTBL ENTRY FOR MAXDPM */
/*          NAMTBL ENTRY FOR MAXDP */
/*          NAMTBL ENTRY FOR MAXIPM */
/*          NAMTBL ENTRY FOR RAPID */
/*          NAMTBL ENTRY FOR MAXLNG */
/*          NAMTBL ENTRY FOR MAXPTS */
/*          NAMTBL ENTRY FOR MAXRPM */
/*          NAMTBL ENTRY FOR MAXSTP */
/*          NAMTBL ENTRY FOR MAXVEL */
/*          NAMTBL ENTRY FOR MAXWD */
/*          NAMTBL ENTRY FOR LINCIR */
/*          NAMTBL ENTRY FOR NORMAL */
/*          NAMTBL ENTRY FOR LINEAR */
/*          NAMTBL ENTRY FOR NORMDS */
/*          NAMTBL ENTRY FOR NORMPS */
/*          NAMTBL ENTRY FOR LINE */
/*          NAMTBL ENTRY FOR ORIGIN */
/*          NAMTBL ENTRY FOR TRACUT */
/*          NAMTBL ENTRY FOR AUXFUN */
/*          NAMTBL ENTRY FOR VTLAXS */
/*          NAMTBL ENTRY FOR DOWN */
/*          NAMTBL ENTRY FOR TRANSL */
/*          NAMTBL ENTRY FOR TRANS */
/*          NAMTBL ENTRY FOR LINTOL */
/*          NAMTBL ENTRY FOR TRANTO */
/*          NAMTBL ENTRY FOR .FALSE */
/*          NAMTBL ENTRY FOR TRAV */
/*          NAMTBL ENTRY FOR TRAVED */
/*          NAMTBL ENTRY FOR DO */
/*          NAMTBL ENTRY FOR MOVETO */
/*          NAMTBL ENTRY FOR TURN */
/*          NAMTBL ENTRY FOR TURRET */
/*          NAMTBL ENTRY FOR 3PT2SL */
/*          NAMTBL ENTRY FOR XYROT */
/*          NAMTBL ENTRY FOR COPY */
/*          NAMTBL ENTRY FOR PDS */
/*          NAMTBL ENTRY FOR UP */
/*          NAMTBL ENTRY FOR LOOPST */
/*          NAMTBL ENTRY FOR LOOPND */
/*          NAMTBL ENTRY FOR BOTH */
/*          NAMTBL ENTRY FOR GOLFT */
/*          NAMTBL ENTRY FOR SQRTF */
/*          NAMTBL ENTRY FOR ZSURF */
/*          NAMTBL ENTRY FOR GOLOFT */
/*          NAMTBL ENTRY FOR GO */
/*          NAMTBL ENTRY FOR DUMYA */
/*          NAMTBL ENTRY FOR DUMYB */
/*          NAMTBL ENTRY FOR TLLFT */
/*          NAMTBL ENTRY FOR SEQNO */
/*          NAMTBL ENTRY FOR TWOPT */
/*          NAMTBL ENTRY FOR MULTRD */
/*          NAMTBL ENTRY FOR MULTAX */
/*          NAMTBL ENTRY FOR ADJUST */
/*          NAMTBL ENTRY FOR TLAXIS */
/*          NAMTBL ENTRY FOR SAME */
/*          NAMTBL ENTRY FOR TLAXXX */
/*          NAMTBL ENTRY FOR SPINDL */
/*          NAMTBL ENTRY FOR RPM */
/*          NAMTBL ENTRY FOR SPIRAL */
/*          NAMTBL ENTRY FOR ARSINF */
/*          NAMTBL ENTRY FOR ARSINB */
/*          NAMTBL ENTRY FOR ISTOP */
/*          NAMTBL ENTRY FOR MANUAL */
/*          NAMTBL ENTRY FOR MACHIN */
/*          NAMTBL ENTRY FOR LAG */
/*          NAMTBL ENTRY FOR MACRO */
/*          NAMTBL ENTRY FOR LARGE */
/*          NAMTBL ENTRY FOR SCURV */
/*          NAMTBL ENTRY FOR PIVOT */
/*          NAMTBL ENTRY FOR PIVOTZ */
/*          NAMTBL ENTRY FOR PERIM */
/*          NAMTBL ENTRY FOR PERPTO */
/*          NAMTBL ENTRY FOR JUMPTO */
/*          NAMTBL ENTRY FOR SRFVCT */
/*          NAMTBL ENTRY FOR PTNORM */
/*          NAMTBL ENTRY FOR AXIS */
/*          NAMTBL ENTRY FOR YAXIS */
/*          NAMTBL ENTRY FOR ZLARGE */
/*          NAMTBL ENTRY FOR EXPF */
/*          NAMTBL ENTRY FOR GOMILL */
/*          NAMTBL ENTRY FOR BOUNDS */
/*          NAMTBL ENTRY FOR GOBACK */
/*          NAMTBL ENTRY FOR SEG */
/*          NAMTBL ENTRY FOR POLCON */
/*          NAMTBL ENTRY FOR LCONIC */
/*          NAMTBL ENTRY FOR THICK */
/*          NAMTBL ENTRY FOR GCLEAR */
/*          NAMTBL ENTRY FOR REV */
/*          NAMTBL ENTRY FOR POLYGN */
/*          NAMTBL ENTRY FOR CURSEG */
/*          NAMTBL ENTRY FOR BREAK */
/*          NAMTBL ENTRY FOR MMPM */
/*          NAMTBL ENTRY FOR MMPR */
/*          NAMTBL ENTRY FOR REVERS */
/*          NAMTBL ENTRY FOR REVOLV */
/*          NAMTBL ENTRY FOR MILL */
/*          NAMTBL ENTRY FOR CLW */
/*          NAMTBL ENTRY FOR SWITCH */
/*          NAMTBL ENTRY FOR SSPRT */
/*          NAMTBL ENTRY FOR SOLID */
/*          NAMTBL ENTRY FOR LEAD */
/*          NAMTBL ENTRY FOR LEADER */
/*          NAMTBL ENTRY FOR CLAMP */
/*          NAMTBL ENTRY FOR BAXIS */
/*          NAMTBL ENTRY FOR LAST */
/*          NAMTBL ENTRY FOR GAPLES */
/*          NAMTBL ENTRY FOR ZIGZAG */
/*     initialize the rest to zeros as the original code */
/*     commented out at the beginning of the block above would have */
/*      data namtbl(2995:3000)/6*0/ */
/*      data cnamtb(2995:3000)/6*' '/ */
/*     CNUMTB ENTRIES FROM IFIXST TO IFIXND */
/*      data cnumtb(14:3000)/2987*' '/ */

