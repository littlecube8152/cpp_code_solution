#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

map<int, int> mp;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
vector<int> a = {1,3,6,12,7,31,48,19,115,21,63,234,22,61,112,54,26,503,23,62,238,967,25,52,127,209,416,124,185,2022,27,53,118,201,420,116,789,286,3914,28,57,172,461,220,930,202,457,1806,227,335,126,854,7859,29,58,105,285,56,30,228,769,1559,739,200,439,207,3893,538,358,15261,71,216,121,492,113,853,180,318,1990,382,566,4093,491,1854,111,189,6716,603,3589,711,352,2007,31938,73,204,100,354,86,939,1619,462,890,3611,678,114,1930,951,8034,1313,3137,713,1223,14851,668,295,3911,1923,8178,864,3144,65473,76,249,423,241,937,356,1956,424,565,3938,582,1231,434,7926,972,2556,94,2006,606,15010,535,4088,1759,7438,1664,2680,31011,3673,7286,4001,1984,15641,3419,7564,1211,128034,95,340,108,873,395,1855,587,306,3955,497,1902,7237,2033,714,3702,548,1838,15898,1589,3439,943,6997,1436,3177,30938,3500,896,7895,3277,14198,1770,7241,65369,8086,1750,13343,3605,720,7209,30639,3036,4732,13480,928,6749,1033,259298,99,240,268,823,421,103,1602,3350,276,562,1668,7372,693,1862,3244,14837,1444,2311,7400,959,3345,31821,1832,657,2888,5406,941,15839,4055,6206,63974,670,1515,7712,1785,14146,6299,31797,790,4849,2979,13457,1754,6761,130445,4837,16106,3667,7607,3226,27456,13551,4073,60569,4706,12255,1707,31968,1741,3984,4178,15347,516559,120,244,433,780,375,1833,178,3470,988,1140,400,7233,1955,3207,1262,15517,1734,3215,7025,1510,3021,206,31840,2156,6867,1817,3981,16130,2978,59949,6079,1121,3384,13005,27188,820,5552,2866,14493,3588,7794,130654,1732,11711,5982,29583,2664,52899,1893,2614,11683,6071,31880,8641,4883,256595,11902,30208,10832,4308,957,64033,620,13878,114056,2091,716,14541,31974,7449,12569,5711,57675,8663,31924,1034314,125,331,176,950,156,1054,371,3881,574,1427,7914,1350,3917,1659,15379,2113,968,6236,1557,474,31973,1229,7656,1757,15464,1469,6376,65076,6275,13003,1319,8120,30223,6757,14308,5365,2764,129456,10412,8153,1669,3957,29409,7391,3043,12393,59824,3221,5297,15844,30066,10544,260907,7423,14037,28630,61951,3831,26676,4048,119501,1661,6861,11229,32545,10577,5383,43931,12654,7962,523510,12399,29510,3774,49185,1586,6542,16303,24286,127708,6148,30858,4201,3939,54118,5307,26116,883,253224,11198,31205,13358,8172,65036,3452,16906,116831,36168,20180,9329,2089236,141,392,167,960,1597,440,857,426,3607,1958,7532,2957,831,1640,13753,2038,7773,1311,30645,2547,1903,7116,3869,14675,7090,63577,1641,4138,13731,4167,355,29803,12001,6244,127156,7528,14605,6123,29935,3935,1428,7575,12370,6199,63228,681,13836,30751,4989,9389,252413,6629,31714,7513,12386,4291,54743,645,32073,122610,4810,3823,20719,15068,62164,2818,1477,16126,500543,17330,15312,1983,52555,3658,23781,127206,3365,20901,14636,3841,62254,10023,243111,11388,397,22192,61691,7838,10908,29731,2360,13043,114523,61162,1023744,39918,26971,5223,119253,17662,9073,4823,53698,3089,238151,12987,22602,1296,65488,1289,107945,35211,27152,521047,7600,30992,5670,43551,130292,13131,55288,5121,232534,60494,11508,26268,121226,5118,43876,4174901,166,409,881,422,1967,329,3148,985,1315,8061,1143,3275,1752,15287,5158,1740,3225,30781,1555,2971,6090,14598,1491,3508,5306,64731,4350,3798,12722,5150,31998,5053,15830,114704,27964,3985,7170,3983,15545,629,62620,1912,14800,4226,30099,6336,258702,24609,5910,14694,63614,15857,29215,120245,8632,26520,12429,62635,6848,9884,498879,25002,52598,3582,6512,21462,120380,10004,29979,6523,1076,48810,1517,4866,259649,1503,2484,32234,57804,15755,4681,17841,129064,14009,28167,51598,10693,1016540,23102,33811,6647,129683,6917,23850,62044,24797,14867,259232,13134,21785,62862,20293,14087,124719,22277,35129,7823,511345,27677,53622,125835,11233,59319,8804,2557,243459,11378,73617,51349,3353,2093395,80588,45668,13978,20857,254303,29451,5548,92507,12113,46024,2636,13184,30532,15581,510087,36626,30564,100157,2277,55412,235933,22385,42932,118817,17534,1011265,10087,27024,12081,7221,62043,184977,47125,93348,514775,60221,106125,33748,2942,242557,45191,1215,26889,87035,8361521,186,496,877,485,1966,989,3992,1263,7826,347,1908,2406,15625,2495,1218,7588,30358,3503,6916,1475,2762,15194,3161,1879,59836,3954,4126,1542,15510,1704,5591,27416,121443,12388,29947,5889,14002,7211,63870,4888,1380,13163,29102,253861,11851,3601,1141,24508,1662,63921,11265,24133,125572,12051,23359,2172,60149,2051,5290,28537,513621,27685,8451,40962,7858,8454,126850,1449,14388,25815,2561,63789,236978,30742,15451,7293,64215,5482,108408,31991,60358,25663,1021075,11392,42647,10254,1324,127582,15949,17385,53297,16683,256834,15801,24300,5970,56418,5124,112860,9246,4797,23273,489240,13502,17209,43327,86021,253881,7003,72601,4955,2064821,13100,112189,13665,46562,258564,32638,49535,19340,110069,490837,18984,93876,21738,3078,44008,12993,258878,12220,28686,38413,974615,18166,57116,14854,123957,9008,54804,242838,29950,63998,30650,121361,465730,32975,20493,128802,36746,255466,46856,100529,7125,44032,4155647,124598,41643,226492,17244,127194,20839,470244,51585,23902,182429,31543,65130,1666,102618,16737,59463,1028457,42080,15863,103536,205076,52589,120516,486699,34532,115317,61548,258653,58807,85017,2076665,6375,22925,8085,50137,80622,131398,11876,20822,476469,108375,26912,55626,160348,987068,89675,214989,8906,119530,61862,510422,27569,84784,43892,175568,16721574,188,414,817,1637,909,3745,1535,7238,501,2723,1188,15553,2970,6515,2340,31994,5955,1775,13183,2658,5190,64243,3843,6452,2335,12751,26730,5397,3664,12254,128144,14044,1638,29333,9762,64858,16011,6386,25363,252537,5234,13941,7174,29560,7468,52637,14784,4317,32109,9298,8078,121723,27457,4261,463840,10498,63895,1531,15117,7005,22832,122996,22500,12712,63682,15823,7921,259699,6936,14511,49381,30250,2566,119747,6023,45526,6046,20141,1038164,24450,50935,17874,128520,17835,54232,19809,3435,244809,61441,1080,99786,15171,23443,483205,6027,26770,57698,109752,10461,33638,243031,34100,27604,124854,5703,28834,7329,2043684,51971,28979,104938,41602,8441,219925,128987,61514,497699,76119,3599,21063,6527,59574,238089,12571,91566,6554,34010,11159,1039843,23820,64330,25358,119682,31983,10928,226212,14528,111907,12319,485212,182806,15104,30772,130944,4143314,25880,187088,25666,108383,488933,111796,47501,12242,244962,21384,84432,1008866,7492,91087,21158,14312,203586,63234,99521,467518,64067,13315,113105,10868,200091,4796,52905,26539,94680,2091202,15254,57388,102392,25359,61104,17753,204123,123403,35776,494214,168501,18244,117662,49036,29179,1014680,107653,211413,101858,482944,10554,68530,175949,8272152,60958,171443,17680,496463,155122,27144,107633,38133,969550,64673,200016,119757,474714,108315,255027,71420,54006,2042038,27026,82960,230045,13922,23983,63871,15351,410343,4622,82585,178037,37431,26714,1048274,155154,93717,60334,462081,112503,35841,212633,11619,126058,45342,6217,4170914,12801,42441,27547,90734,238240,7356,118180,506846,47364,74829,161244,1043690,92189,28154,63142,32276,225771,106452,469508,126298,227453,1984768,252183,36625,514995,190505,80636,952179,42002,303371,205019,33432632,190,502,860,300,198,1794,3249,489,1466,6504,815,3391,15034,2417,7891,3884,32154,4424,2136,16140,6840,62000,11109,2564,5400,28007,13368,2926,129398,13834,2001,8072,30855,4094,51577,965,17338,4520,15750,255903,14898,984,30905,13279,63538,8220,18998,126915,5810,10334,25635,40925,5139,518092,31541,6291,15954,64120,13370,23928,118934,4914,27151,52758,9685,239649,14094,17277,64919,19639,122930,28764,991154,13056,60604,15905,16910,124062,22584,2919,58485,240166,41388,27086,123731,28462,54761,512142,53793,32601,130556,13821,31087,218607,25526,84797,7660,50912,1264,2067304,52393,66382,21312,248247,29573,57776,18876,113680,58243,22595,508042,31439,51149,98762,52221,5360,213240,15100,114437,13538,1031337,8477,23670,122227,44624,252371,46176,90860,23709,482144,69538,13711,26756,232098,69010,14934,41201,4152627,105929,203803,9107,58782,3566,13907,130611,456073,247873,43695,129852,53422,1045496,56786,104917,47816,258636,61296,429121,37865,76813,1765,24458,10740,203126,108832,2062688,4912,22737,124122,10954,260872,77249,481503,16590,76777,218578,120550,5666,975765,42749,244802,64732,102297,488963,58435,69553,8171051,225858,75655,489552,54344,110217,40521,24366,200033,90211,1012355,68745,205857,439130,42144,14831,90146,207836,22284,2069461,212488,121138,1826,441569,258766,120794,56811,933424,233328,86178,482330,97608,30946,190575,4165537,50524,108960,248873,73190,499524,100644,244130,51289,72638,3803,1017147,72004,205868,82025,64842,438774,142421,2090565,107887,62046,228575,447315,8624,61712,80071,222745,917927,138728,441587,188277,119900,16424077,165616,50436,1000132,122765,161816,9093,484652,50105,95200,1949239,90083,215760,106909,23006,373906,55096,113052,970390,158389,504184,3959829,51820,237398,514737,122197,50388,217772,96075,1024475,44688,182529,85514,520511,117322,57828,32614,203324,2013384,94436,387977,68486,259271,1011183,192197,19971,477574,251021,8355640,46836,74947,242734,39514,22788,109785,470974,36848,11766,245762,60911,894368,51559,82822,418225,157001,2096678,17411,49110,326200,96865,882917,312046,121314,3964102,179733,497486,63081,130688,245550,982340,126857,214828,110320,441973,1854445,243329,73322,48759,378738,23353,811964,89370,289974,51950,67103382,221,435,882,1599,449,3488,766,6170,470,3061,1288,15622,2932,4741,31941,3778,6573,2981,15268,3491,6930,61945,5835,12452,1493,2894,18771,3614,5953,122105,7118,26677,1962,53468,3753,9516,31502,10202,260432,5993,23570,4788,9220,58846,3840,16166,21485,126410,31344,51093,19271,488768,15266,21942,127310,4822,11459,29345,13063,223080,39212,5295,2797,25677,119741,32369,9653,54807,25241,15726,1044603,46765,26113,121939,25749,58200,4557,238936,46501,17030,109306,59543,11857,24775,509273,12175,58640,6529,90682,238013,10598,30016,55976,31160,6289,2023096,40480,101080,25932,46438,206568,8015,124466,41927,507848,58473,6992,123654,41820,8510,241697,66460,29398,55631,17933,1047605,8319,39963,124930,43191,258789,57809,453072,30411,45835,120975,210597,114359,26025,4171793,58630,4874,22362,97059,32358,260773,399727,83102,204106,64928,21881,128686,63567,1043058,73338,12197,230002,130085,12259,461264,47174,189720,18332,2008214,6110,736,147930,26286,104249,51351,492405,42107,10847,94775,237071,34384,984798,228147,110594,23587,462203,120657,16364,8181672,140771,490627,65292,12514,191939,920750,14790,33945,110132,149359,467256,124647,19496,243775,59903,15739,118637,46530,2034488,10200,127938,16462,348373,238830,944330,165393,59985,19860,512800,183812,4082033,29555,149332,28582,122335,37601,485516,100862,52808,236500,104016,958967,61072,165248,11953,488191,30110,86496,1921305,129041,252015,457795,25407,91163,175050,1019602,9103,171963,398454,47306,110749,147344,50194,16661107,217445,112782,52237,379352,865565,473121,23352,77098,245454,1988826,192588,36402,407364,130206,34056,248468,52912,70209,1015644,11895,86999,364338,128225,247786,114757,4145040,261372,14906,415076,881418,25291,160809,21720,495379,172001,2055241,68956,17741,270316,244816,801693,114633,471218,211108,8353126,45501,116490,4056,135221,476694,23302,137976,1031232,228966,102654,474382,68533,1937794,97022,237410,47226,462485,639544,63591,168573,4115669,5446,185098,99781,4745,572682,14363,417070,1911734,12261,274671,250735,980889,373672,248640,15389,47278,33160203,101038,982532,225004,463949,1925904,99302,181968,349857,985138,37226,343622,95639,166048,4093217,260850,114053,365417,939890,84433,253508,118898,459555,145443,117203,1927681,105443,522831,36243,816661,175691,8191,102419,15329,513288,8139841,125798,196782,122782,5652,514973,98016,964333,426159,256561,2006208,102501,147939,412594,31362,257068,28061,957762,139832,492681,157721,4167100,332422,219648,804843,309158,2052230,755485,2494,16495906,251168,88233,54500,514991,48972,104832,878415,202167,487818,221723,45819,2019922,149558,423344,64992,793324,237920,126003,14773,3910583,59379,283088,180010,958670,151354,27170,411509,1837963,195121,639262,278970,8200859,121923,51688,476397,72661,883436,3988,129554,151493,470629,2060772,377014,1014477,170094,53702,486152,23388,113301,213878,128354,4089200,31192,171544,321576,812698,338003,1737407,838134,208007,334873,134124895,224,441,797,467,1372,4009,674,6989,1360,2832,14425,3273,1441,7321,1567,3746,28158,3725,10287,3636,60716,12512,5551,30254,625,1690,7127,8409,130770,3408,20300,4120,16375,5540,64233,15032,32591,11648,261191,3887,32439,59035,1891,11527,108834,9162,24954,5432,36101,12449,1995,519931,14193,46744,1702,109072,28933,65107,26692,15062,247879,43999,22133,11285,126040,34599,22899,1030178,45541,15721,6007,130062,207512,26647,50477,26919,91391,14986,17275,474202,117175,8802,6645,30950,228605,17643,59514,732,107914,26434,2015528,30368,247497,21893,52182,30457,103782,464324,11270,51794,22238,121693,30672,201097,58386,103493,27548,1004065,14693,44176,121711,218279,39135,27796,102666,472227,91273,20060,54739,208807,108751,4177600,184743,9714,59007,76889,511155,54438,22752,82664,175946,18676,44391,1031590,82534,15211,16984,37935,257403,110101,515799,110550,186788,19003,2032539,54127,28418,186249,97586,498299,121043,203267,990854,31056,59087,12348,204493,87164,510295,182126,8295605,100352,213642,18733,67151,488610,172562,62725,129879,29107,937232,4806,205159,394815,34246,213889,2087062,35338,107136,50865,231078,14951,64867,21679,381703,62434,993746,14335,101385,139767,34903,510306,3988196,13854,154288,69144,17964,462016,113532,148246,44341,971274,63766,247718,120016,485113,186763,46596,1970300,150995,124220,496255,185864,7984,39765,921443,184677,64637,421842,16617145,136657,306655,24161,918368,213107,99020,485717,88729,219272,104637,2083419,31256,6666,150252,116597,497112,116412,4872,171273,824727,428918,232739,4104414,40929,30528,10587,194581,31829,63280,327742,1017814,13217,110204,290586,233201,107048,1916085,430543,149744,98370,975344,272726,217225,80365,8287883,336334,74936,207001,7981,961404,181001,430422,107940,53606,199803,1992106,105847,234844,448533,805135,63399,163430,520989,211634,4142343,16127,340585,174896,832049,446239,241931,2078345,132844,428956,229917,699861,132224,7399,33420334,289466,843681,516422,183713,2069093,224616,520543,68905,58164,892517,87662,135578,64538,523108,3978203,78969,206007,408522,140639,13703,1023415,492754,2050203,248498,424692,54269,905765,234503,97071,450267,245858,128698,8334578,65165,180437,28787,80030,271175,65328,32157,1009301,138126,470069,192545,1743114,185402,995813,220216,489558,197441,3838592,810995,186000,18410,399638,54537,1862056,255636,510275,791813,146298,371461,16672624,52458,67844,219666,128872,511220,199338,1004681,213576,394008,1840940,474562,932491,88920,260047,23837,384379,4161874,215759,353901,922212,1634538,235940,522538,32564,795937,170594,485133,8261852,463084,905784,256929,105587,1825920,91883,53459,452053,999662,102919,242384,128302,328618,114931,4128724,242007,378850,763957,1980641,671957,496833,66814730,799435,361720,173901,1825585,236139,995618,318091,147623,4167057,265833,821385,323076,1903710,31808,455403,98376,864349,457839,254492,8271663,481114,55856,976211,380613,236768,100401,1850270,360456,959491,465035,4122032,10479,502433,847589,1776703,233788,576084,487396,160995,16687976,201099,11064,475657,137677,26917,969737,65214,521108,2068585,364155,191752,732744,4055670,56542,166422,56901,281492,807905,117339,1813275,372508,56763,231545,977109,374332,8263338,1132498,30349,406029,217283,53328,1047909,106602,507533,3821685,120399,1034775,77684,45150,1724355,508441,90984,32972029,56888,85459,185830,351244,947237,287402,1814132,955962,350775,150334,4015434,420618,197446,117503,1018287,358128,132255,1732697,46925,660807,8266402,264534,1047427,1665899,338265,860520,300602,4108430,8865,58584,463513,985512,247439,2036091,1001801,380180,16360616,814697,1575292,35153,3452941,787772,429012,2016358,452787,593323,193553,7822830,32947,162816,1306942,3751070,35354,107256,252924,128574,338222,1033086,408358,1787394,11905,21495,828943,267933073,242,430,971,1712,3204,795,1502,7371,1565,13817,2359,1254,7755,2541,31837,3949,792,6680,15063,7935,58715,3243,13925,7665,22127,126322,7417,13724,6760,32016,12351,61576,1547,3885,241102,31704,8280,57969,24285,7034,9380,129072,13463,25539,65268,28303,518567,28516,7120,52960,8463,27549,106031,14012,65377,19127,7816,15945,254647,30313,57453,11142,19151,115835,995596,14774,41940,32301,74382,13205,251642,24644,4225,110323,522860,6301,27994,47018,114867,57679,248700,50567,108996,4873,49779,2032054,14181,112638,47562,248587,49336,29725,121493,51781,501846,49221,19298,98784,61773,182055,12548,984380,41346,117456,6865,217914,53457,14195,103934,502443,1273,125868,40878,170994,4175172,10231,88435,203149,31771,99215,493184,72786,249241,14844,71715,1008202,75230,6488,56551,28721,250359,33714,407915,255154,49541,2044533,192002,49907,18475,427217,49673,88561,252533,24741,34804,939076,19493,114853,283771,37504,219991,105392,33169,8364066,49794,99140,219046,94320,65457,480363,83337,246339,922541,37430,318852,136337,26721,55865,84321,2027013,65410,202438,127389,55797,452194,243465,965524,91573,352967,37963,69353,253480,118988,4192545,46766,123529,19846,261183,449014,190807,91011,911115,66663,32053,7550,460964,78878,62708,232928,1767259,129864,214587,40607,78157,981913,4659,40302,20132,466252,16737383,339535,144275,974188,40662,149682,73084,22911,10922,411432,241855,1994881,87517,50700,207253,446543,21819,105246,876467,31279,126965,280481,3936724,9366,149012,31324,272538,52408,902205,43497,452530,24014,103253,162399,1807910,98618,838699,218149,31317,276026,8168817,68338,460993,146182,96663,923960,210792,407184,1835453,165568,407283,63593,126797,986348,7373,53423,118322,366025,4143391,153325,517479,17288,12820,171899,783096,231727,32765,2003864,84454,221413,465582,820565,160605,481088,73166,32820340,248661,444898,72545,188641,1911579,452695,111879,926296,335720,129644,4037760,97293,508455,57800,149302,889797,464858,198782,2024130,12464,166926,293241,940337,207610,67278,22324,310033,8383599,34824,367040,63984,885948,174915,71622,1690142,45086,400664,103245,135086,933146,182796,467747,88500,223972,4103033,217367,499292,130666,240580,815467,460021,1970707,301513,985295,425061,16690958,111347,215024,93891,466632,83595,674611,2076243,184462,418371,792456,50204,130414,190895,400655,254484,4075619,177554,750795,248173,1780123,519149,956886,60849,3659,7900879,72010,901765,224214,1902506,575243,3840648,501614,860887,33609,311736,59611,1719355,857104,453222,66613942,973154,167735,1806299,292047,88631,785774,32136,63737,3925724,1428885,103756,23434,332237,88073,211106,111133,713806,143255,8352915,208851,60577,494309,72901,252857,906703,2082153,803869,164318,117324,3801359,614315,139827,75691,340206,1970762,150748,1032287,16543336,36784,214943,413912,32763,925057,521289,232884,80282,1963198,396423,230565,918087,261630,3820986,476018,1040408,179681,464633,1661924,137107,960978,102545,24283,156220,375642,88898,8340874,329365,867968,181447,111408,1238021,65120,426499,3170616,1904018,1029059,33292761,238837,58266,434195,148311,848657,330749,1999278,350602,49085,156999,124083,851643,3869617,518570,823137,1712180,292837,1046705,409079,39524,193936,8010771,180773,932264,161525,468652,181471,1960244,130234,350688,89982,736987,4045346,365591,892002,246687,416832,1964101,332991,706825,16627135,714972,325462,213050,1869353,421452,3587161,438521,210722,1838654,518479,8285389,709987,198068,273185,55203,1953585,559266,3389611,283177,245562,1750840,174936,688787,132472839,204293,452926,3976317,885123,235195,1971540,215697,476421,938464,303138,8385307,6016,471884,870767,38503,521401,1937764,270140,885136,37659,372043,47793,4098690,471080,1377783,610803,324609,16421294,113531,956343,58839,286214,204741,2081270,423607,63664,3560497,218844,95921,31001,703144,385631,1541031,391132,8361609,361746,230448,615102,3079925,750831,373063,1838797,339634,32909992,407065,1022500,19272,223665,361980,1988842,130629,207188,462119,173527,735054,3952441,240756,510074,1064038,932892,518263,214275,8059326,256973,964965,1073372,58991,3783006,22225,345368,1018812,463506,1514916,16474415,349892,1373550,236155,505572,3600800,354331,1034469,338017,1603255,1039858,7906140,346287,794288,60817,457763,1778187,715867,3795612,636056,87387,1855966,293629,858651,122711,360866,66861277,191595,71884,700800,1809710,57477,561252,317890,4167633,9862,502220,999980,242834,340550,1770245,167606,977871,97899,7444077,360977,1595605,800799,230398,468180,23883,4109843,41663,782367,133330,442080,92944,200137,1969047,208983,522461,967547,16652506,865713,224040,106723,1809747,3318389,834475,1369769,357521,7344102,1971801,844388,4193235,1199257,395403,1004595,33248776,127267,468449,566466,1420033,192392,271936,3894943,977020,1677300,672925,327831,8242351,254864,1454639,106573,540261,3814848,16150207,408065,751604,3725293,1139758,579337,8221529,311686,68573,619075,1863782,573731,142065,3197358,1176244,536580648,349,798,482,2003,3132,1197,7275,631,1151,3962,14991,3328,4925,32160,5814,3048,14148,7522,63398,4538,13230,6792,29173,10729,124969,7658,13861,30819,15633,7136,58433,15676,19598,254403,5614,16732,10657,56497,30762,122462,12883,17148,47332,8644,516801,11964,42371,21803,15459,117172,40757,28055,234820,4700,55761,14099,27813,119516,24340,13415,53314,1020118,32524,122442,6908,1483,12502,24738,10739,260118,13558,27892,48984,116047,482658,65453,10147,19356,119013,53555,250601,36840,101083,2044111,38578,8825,115623,46638,206784,128960,4373,478627,35150,87566,191604,59206,1022694,28137,87938,24622,46431,253036,29898,55346,411145,6563,124179,259636,110838,49534,4149556,123564,10765,54278,261929,59696,450488,63603,125526,38027,199801,27158,89581,6979,1045320,80052,253790,118959,38486,475666,69276,1944855,20125,75387,4734,60792,22934,255259,37169,361764,1006109,15122,155792,48750,439716,87586,220182,26987,42559,8302420,59034,128657,61303,521858,63961,943918,114183,62367,25141,268608,13843,239454,2004525,185553,17758,41445,117051,400739,146287,1008910,56943,255721,36095,473307,257817,55653,4177244,62404,15776,258943,514167,17147,169368,940565,79966,55151,322817,18231,15895,1902608,141408,475424,13236,49556,874080,169361,2916,118666,378700,16755973,146933,434054,28866,878785,30182,245510,477432,226940,2038676,183757,490915,222939,1029207,30958,247802,44409,3855364,324688,6340,170014,36842,17576,98928,36009,1030652,158247,70750,12116,342461,1971211,121066,173833,351071,917805,211729,492273,118225,226414,8336557,215458,422200,102785,256432,108922,1033216,180030,440708,246383,1955313,503917,184765,7521,44720,997396,108818,171876,417233,3718787,40059,894910,251268,386565,120103,1823019,37361,154909,32781043,673154,205658,435525,29770,225044,65942,2077968,515917,1030250,300522,69853,219816,4154638,154566,8684,726514,329504,185527,2013448,162539,350257,948529,33538,420026,101129,63607,8366761,103107,379980,221776,12225,988583,38356,101470,417108,2027010,211430,84135,375257,847217,98195,444191,4058207,209600,453941,207214,130774,951821,342665,216429,2056110,235225,487014,196628,16133755,174511,37995,484506,206458,969101,42419,294504,2042717,107979,460939,94973,23395,938326,285864,4069574,249828,700751,474715,1886414,430704,240866,822747,8368090,192703,850283,490270,180407,2045233,163591,706483,363880,185143,4038760,308526,909213,122987,288875,1803846,210933,820336,66748208,717164,1812635,140141,531821,340105,4031987,118053,340502,1036436,434134,1580760,961665,6486,7996326,410780,1017716,451224,1897578,105712,131532,487093,54707,117201,185126,908393,477130,4034757,746402,267803,2081898,622122,16565204,216447,722187,191559,2046516,204146,440638,211192,999114,203799,420820,4047490,231133,366525,1553598,402571,930890,474319,8257934,299369,23865,181498,950685,30643,136211,361103,1343950,114162,360635,3752413,1043453,124794,240791,2020819,232146,1046970,102837,196043,33192223,162441,408846,45081,224912,109485,748155,13095,236520,2070179,61770,535349,3812074,410352,16132,865365,133580,382667,1763009,205283,7380051,2041465,84565,133134,493179,122478,3238056,2078109,351479,982566,129431,16510904,747507,299793,253145,55952,1724070,855528,166045,3894873,352531,949772,1664512,765353,432062,8169535,354735,1287778,37574,992903,4097194,219975,704087,1949489,285726,133879010,103928,1900683,641106,342149,3852909,840232,404100,1586131,5821,982744,249067,7989420,374169,933208,1318429,182177,3831797,800480,287299,1907175,32897,585042,167484,16287952,500713,850313,58303,221869,456945,1950148,174750,378299,981967,173551,3361554,196969,1598483,632254,8086134,70724,195545,649732,468897,1859031,335199,110150,916534,3721377,417497,903059,1604324,454254,840792,237909,26161,33494662,926203,510708,177615,113988,1372993,278121,3476483,11492,296580,1779850,791777,236314,7951973,373159,821131,1799106,342142,856314,3686122,555775,1655075,79248,239085,363362,899737,16659642,97533,155616,58904,909009,102227,457634,3166220,9237,176256,8289251,1323933,251927,652075,1532,4158244,478832,1045820,1961855,617681,83258,66676534,200806,955141,1766462,506440,172246,1005636,437781,49515,4168266,56467,151329,306196,818370,490669,157129,1901795,75819,42719,7584696,130344,1859790,3840346,988776,407270,1902193,940661,16537269,281242,1429162,232652,3317766,1036643,1933999,265400,923181,165866,63684,8248884,1020184,372938,1923586,240319,3561200,877799,164752,1657032,489347,642353,181871,33430466,363192,14097,233717,957556,1720661,3335475,716208,1707546,141992,111006,273519,585031,7827988,1799166,558054,2701226,431633,16178378,36677,500834,1009698,346984,1495528,424619,3064245,968478,7855246,83367,357894,1087915,4182401,478148,126692,1075082,267793198,1572541,787344,174256,4131430,7081733,153658,1721703,609195,3720919,531526,317160,2014848,1019198,16428395,1459733,132741,808270,4087146,363217,21099,1334535,238993,630801,8340870,625243,1589924,3642211,749020,329847,1652817,982361,519239,132657,33471469,187896,974967,2025512,3567316,813953,345538,228423,1912356,1037113,7944473,825918,1678228,3342653,547444,88349,1995571,804561,57923,404172,16506474,166015,1816534,3714954,941897,1418422,8286515,240823,377664,839147,2695088,1280356,561315,225986,66779541,224885,286561,919692,79147,245233,510339,1510358,387842,3372754,1083716,8212592,197278,296073,794185,511384,1931253,738735,435110,202029,3299507,1913525,356774,851459,16558400,1606165,3392992,19630,1820458,1023422,8057020,1668495,3947787,135074,918544,1883238,168281,98217,886846,33303622,916074,2037791,3577693,722511,431596,1711908,54039,8111639,1704406,124592,3482750,470723,749509,15506406,680332,1557935,4080919,488984,975026,487788,167980,1490879,6750601,3749824,843573,428898,1113456,133818927,43879,190331,697650,142934,28144,3047215,331455,1019702,118866,372697,2008921,6541967,282490,915856,3587953,1266678,16465145,1963946,269221,3280235,6774074,89914,342925,1422,1718986,925123,154454,3740625,1030034,1890013,231432,356136,32807734,1025394,197977,1501160,2996092,1043407,107846,7877889,399681,797964,1284400,96931,2899375,23564,1033538,16262048,107107,649284,122540,1536300,4163634,952628,7184071,656590,408474,1597121,4182669,202452,499169,2080574,66236651,301831,966200,466671,2262783,1748800,164183,7968246,4079223,213892,396250,15834894,824908,2683817,989038,6616345,2093837,900206,2875185,681393,32769576,1762699,998715,275186,175218,3374115,2023997,122941,8203090,2219971,1614868,629523,119950,16724882,99965,174656,1473569,906292,3335627,1297898,220001,7767307,2304741,1883736,722390,1073223220,368,787,481,1934,710,3713,6637,1829,446,2109,14755,419,5973,29030,3986,7341,16254,5276,63801,5384,15848,6938,2175,32266,5893,121288,6161,14894,25887,11819,3977,55061,31561,245843,7890,30972,55726,32571,115169,6069,22488,15394,64448,19205,10330,517902,15204,30558,11446,94258,21963,54694,3321,17696,15138,223271,9118,24645,126586,16470,41200,1003150,25601,130126,52508,247876,47187,99193,952,27555,44164,513261,27637,50896,21407,151676,31710,114084,46564,2032299,191203,6883,33381,1894,67414,10907,496656,60720,12056,114775,52211,4697,223337,107920,31590,1013155,16909,58369,23659,127502,48556,229210,96774,27505,500064,216426,4183344,124538,207343,18398,42346,86304,32331,511055,17097,216537,39788,983603,103633,57178,13710,241938,88043,60968,494742,64307,24723,181666,48236,2011504,80063,16992,216992,508209,253787,12361,63188,80769,1029216,73455,250383,31396,426260,223700,13714,8363626,108520,247765,97816,331137,918131,130053,39363,244642,439936,116829,197202,47783,2024916,64682,159704,428082,9695,145179,123552,917027,8388,405619,119421,241322,80735,4148863,57435,91705,179582,42152,472298,824588,39395,72607,510943,2077930,14448,6795,311379,1033730,22438,103998,400486,184046,27076,16692953,290143,208576,50880,99360,886803,443160,244570,22785,2000748,181934,394994,253163,944009,53022,249838,471198,4011413,137870,371322,110368,1023858,87032,192919,24326,423035,219564,1973698,280236,83342,139550,1028596,312606,8129570,197119,57260,487233,14548,98752,224473,105549,1032810,31958,125682,375186,30646,1845251,161491,377216,5593,858554,483733,195490,3886362,19471,243302,1007203,211831,476425,1914119,226804,78291,394337,916970,145921,44937,9285,32643111,86210,278969,1889522,149358,485479,23585,155087,852162,13487,394919,133206,4176205,498798,871739,107952,344588,19215,2018661,130010,143800,1036080,185682,8306754,165735,468923,253773,809898,88190,518579,227683,2085828,281551,81558,199285,833770,3869596,207422,372919,1017573,229068,425082,1672125,795938,67103,451048,16724851,189691,38855,80929,725442,101783,1789310,448147,181241,949177,109820,415808,4181425,120898,473357,558364,49383,2037699,200225,7842700,64394,983945,12212,116104,1766646,240096,728101,419991,4024699,92972,472893,1024104,1073817,303808,66717211,2035788,9473,3866992,276106,261119,78090,1034923,333284,1648153,149461,529728,8092262,199164,959879,21706,192800,49902,512451,48376,2023641,729249,320466,120177,4056134,429424,1044677,360576,1582444,851333,109513,51262,354374,16157509,66840,502141,1935638,38044,383996,155701,42400,707888,38541,142569,72791,4064223,477349,983334,375873,46727,86914,254657,1860282,52434,7409861,438913,35441,1009937,342711,1806531,861609,60823,229377,512847,3088551,13438,430929,107381,532135,33069838,158941,955642,255546,87654,404543,1878515,179505,37600,369757,59850,877228,281122,3820404,897271,389649,1878831,430070,1010888,511201,8322003,356080,789865,1960062,896414,478228,3969441,896780,2022006,60389,367404,615329,16740791,483650,1310780,20315,129071,858520,3748133,242618,634685,1621941,7411476,110880,1326707,270091,3544604,354538,731889,1623249,133410855,1977007,3884117,1000900,1387753,487987,8356545,707356,192462,444487,1720488,727098,250268,4023018,638896,1828042,313816,166199,105011,16146200,243559,419658,865341,231324,2021214,751705,4180734,13949,375919,1532930,107177,408370,214737,919614,132639,382770,8215213,556449,284913,1738516,195408,69327,593250,69792,3432508,39723,1986705,810172,370654,33323475,52151,162014,430328,629755,1901537,151124,630836,426742,4026083,249717,983061,49389,1158425,7714482,220170,394011,1888003,897877,80214,4079509,510348,1839240,50525,16547690,856243,200690,395801,1526262,282088,2732385,926101,7917809,133638,696238,1216911,509770,3997746,57344,763353,1895528,66365925,464594,95119,832244,1579661,379705,739290,4142597,2777,387926,827690,233627,361489,1566356,108738,60133,335828,77180,8280872,11566,311747,1563975,657342,433785,4048219,849216,1851113,16501399,280886,109770,1854548,388357,100554,3774669,1516350,6906077,560870,197852,274015,4152417,43423,422807,125943,949291,1688380,32712880,540005,1861867,3558659,141880,695576,1872448,956156,376681,8336012,850713,1904989,605209,3354577,263117,1970032,703882,16684812,627688,1895900,322294,573494,3777617,1834047,7691731,34914,511563,150375,2092745,3198843,1572626,998611,265582755,2075956,288127,59076,7734671,331653,2586206,21853,1051367,393000,16666178,66856,438966,1761607,589808,4141072,937721,1561191,522858,8139430,1041657,1773556,3659315,451885,652675,1703261,32668755,612202,1614284,974702,40877,3929056,724012,300625,217551,30697,2094654,360222,7667532,216291,684631,28016,270776,1507527,3936615,1042991,89176,1402766,16268282,724952,16296,1945362,467452,647984,36573,3967716,549368,360534,2065725,7765877,911613,205294,2298583,1562627,67065896,1031476,75169,1895003,747704,4106320,907442,1738963,311601,734163,8269357,116179,406718,880892,272482,1934772,586649,3662949,1699161,241179,879202,16191958,1856469,988387,3830634,918159,7062369,514886,986243,1387447,4184066,966265,1669435,150033,961799,407671,32831124,1808700,3707588,6686699,2039473,3486037,525127,1728927,784277,16749805,579933,1866909,766362,42599,3539547,498900,6864941,1351263,223856,765416,3927396,502621,1318980,883941,134119367,1044330,1836963,150845,374134,649920,3942292,120447,582014,476445,1852103,341740,801532,49671,350709,8061616,1339605,689263,3559875,1942946,764388,16742931,855897,1067680,514658,3819304,582626,1051136,8276256,557406,226248,504044,1653456,895390,4192344,1200457,224128,32953028};
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // cout << a.size() << '\n';
    int N;
    cin >> N;
    cout << "Yes\n";
    for (int i = 0; i < N; i++)
        cout << a[i] << " \n"[i == N - 1];
}