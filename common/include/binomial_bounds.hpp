/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#ifndef BINOMIAL_BOUNDS_HPP_
#define BINOMIAL_BOUNDS_HPP_

#include <algorithm>
#include <cmath>
#include <stdexcept>

/*
 * This class enables the estimation of error bounds given a sample set size,
 * the sampling probability theta, the number of standard deviations and a
 * simple noDataSeen flag. This can be used to estimate error bounds for fixed
 * threshold sampling as well as the error bounds calculations for sketches.
 *
 * author Alexander Saydakov
 * author Lee Rhodes
 * author Kevin Lang
 */

namespace datasketches {

static constexpr double delta_of_num_std_devs[] = {
    0.5000000000000000000, // not actually using this value
    0.1586553191586026479, 0.0227502618904135701, 0.0013498126861731796};

static constexpr double lb_equiv_table[] = {
    1.0,
    2.0,
    3.0, // fake values for k = 0
    0.78733703534118149,
    3.14426768537558132,
    13.56789685109913535, // k = 1
    0.94091379266077979,
    2.64699271711145911,
    6.29302733018320737, // k = 2
    0.96869128474958188,
    2.46531676590527127,
    4.97375283467403051, // k = 3
    0.97933572521046131,
    2.37418810664669877,
    4.44899975481712318, // k = 4
    0.98479165917274258,
    2.31863116255024693,
    4.16712379778553554, // k = 5
    0.98806033915698777,
    2.28075536565225434,
    3.99010556144099837, // k = 6
    0.99021896790580399,
    2.25302005857281529,
    3.86784477136922078, // k = 7
    0.99174267079089873,
    2.23168103978522936,
    3.77784896945266269, // k = 8
    0.99287147837287648,
    2.21465899260871879,
    3.70851932988722410, // k = 9
    0.99373900046805375,
    2.20070155496262032,
    3.65326029076638292, // k = 10
    0.99442519013851438,
    2.18900651202670815,
    3.60803817612955413, // k = 11
    0.99498066823221620,
    2.17903457780744247,
    3.57024330407946877, // k = 12
    0.99543899410224412,
    2.17040883161922693,
    3.53810982030634591, // k = 13
    0.99582322541263579,
    2.16285726913676513,
    3.51039837124298515, // k = 14
    0.99614973311747690,
    2.15617827879603396,
    3.48621230377099778, // k = 15
    0.99643042892560629,
    2.15021897666090922,
    3.46488605693562590, // k = 16
    0.99667418783778317,
    2.14486114872480016,
    3.44591466064832730, // k = 17
    0.99688774875812669,
    2.14001181420209718,
    3.42890765690452781, // k = 18
    0.99707632299691795,
    2.13559675336844634,
    3.41355809420343803, // k = 19
    0.99724399084971083,
    2.13155592217421486,
    3.39962113251016262, // k = 20
    0.99739400151915447,
    2.12784018863251845,
    3.38689892877548004, // k = 21
    0.99752896842633731,
    2.12440890875851096,
    3.37522975271599535, // k = 22
    0.99765101725122918,
    2.12122815311133195,
    3.36448003577621080, // k = 23
    0.99776189496810730,
    2.11826934724291505,
    3.35453840911279144, // k = 24
    0.99786304821586214,
    2.11550823850916458,
    3.34531123809287578, // k = 25
    0.99795568665180667,
    2.11292409529477254,
    3.33671916527694634, // k = 26
    0.99804083063483517,
    2.11049908609763293,
    3.32869446834217797, // k = 27
    0.99811933910984862,
    2.10821776918189130,
    3.32117898316676019, // k = 28
    0.99819195457286014,
    2.10606671027090897,
    3.31412243534683171, // k = 29
    0.99825930555178388,
    2.10403415237001923,
    3.30748113008135647, // k = 30
    0.99832193858154028,
    2.10210975877822648,
    3.30121691946897045, // k = 31
    0.99838032666573895,
    2.10028440670842542,
    3.29529629751144171, // k = 32
    0.99843488390555990,
    2.09855000145353188,
    3.28968974413223236, // k = 33
    0.99848596721417948,
    2.09689934193824001,
    3.28437111460505093, // k = 34
    0.99853390005924325,
    2.09532599155502908,
    3.27931717312372939, // k = 35
    0.99857895741078551,
    2.09382418262592296,
    3.27450718840060517, // k = 36
    0.99862138880970974,
    2.09238872751677718,
    3.26992261182860489, // k = 37
    0.99866141580770318,
    2.09101494715108061,
    3.26554677962434425, // k = 38
    0.99869923565267982,
    2.08969860402822860,
    3.26136468165239535, // k = 39
    0.99873502010169091,
    2.08843585627218431,
    3.25736275677081721, // k = 40
    0.99876893292508839,
    2.08722321436752623,
    3.25352872241415980, // k = 41
    0.99880111078502409,
    2.08605749165553789,
    3.24985141664350863, // k = 42
    0.99883168573342118,
    2.08493577529222307,
    3.24632068399498053, // k = 43
    0.99886077231613513,
    2.08385540129560809,
    3.24292724848112357, // k = 44
    0.99888847451828155,
    2.08281392374021834,
    3.23966263299664092, // k = 45
    0.99891488795844907,
    2.08180908991394631,
    3.23651906111521726, // k = 46
    0.99894010085196783,
    2.08083882998420222,
    3.23348939240611344, // k = 47
    0.99896419358239541,
    2.07990122528650545,
    3.23056705515594444, // k = 48
    0.99898723510594323,
    2.07899450946285924,
    3.22774598963252402, // k = 49
    0.99900929266780736,
    2.07811704477046533,
    3.22502059972006805, // k = 50
    0.99903043086155208,
    2.07726730587160091,
    3.22238570890294795, // k = 51
    0.99905070073845081,
    2.07644388314946582,
    3.21983651940365689, // k = 52
    0.99907015770423868,
    2.07564546080757850,
    3.21736857351049821, // k = 53
    0.99908884779227947,
    2.07487081196367740,
    3.21497773796417619, // k = 54
    0.99910681586905525,
    2.07411879634256024,
    3.21266015316183484, // k = 55
    0.99912410177549305,
    2.07338834403498140,
    3.21041222805715165, // k = 56
    0.99914074347179849,
    2.07267845454973099,
    3.20823061166797174, // k = 57
    0.99915677607464204,
    2.07198819052374006,
    3.20611216970604573, // k = 58
    0.99917223149395795,
    2.07131667846186929,
    3.20405396962596001, // k = 59
    0.99918714153457699,
    2.07066309019154460,
    3.20205326110445299, // k = 60
    0.99920153247185794,
    2.07002665203046377,
    3.20010746990493544, // k = 61
    0.99921543193525508,
    2.06940663431663552,
    3.19821417453343315, // k = 62
    0.99922886570365677,
    2.06880235245998279,
    3.19637109973109546, // k = 63
    0.99924185357357942,
    2.06821315729285971,
    3.19457610621114441, // k = 64
    0.99925441845175555,
    2.06763843812092318,
    3.19282717869864996, // k = 65
    0.99926658263325407,
    2.06707761824370095,
    3.19112241228646099, // k = 66
    0.99927836173816331,
    2.06653015295219689,
    3.18946001739936946, // k = 67
    0.99928977431994781,
    2.06599552505539918,
    3.18783829446098821, // k = 68
    0.99930083753795884,
    2.06547324585920933,
    3.18625564538041317, // k = 69
    0.99931156864562354,
    2.06496285191821016,
    3.18471055124089730, // k = 70
    0.99932197985521043,
    2.06446390392778767,
    3.18320157510865442, // k = 71
    0.99933208559809827,
    2.06397598606787369,
    3.18172735837393361, // k = 72
    0.99934190032416836,
    2.06349869971447220,
    3.18028661102792398, // k = 73
    0.99935143390791836,
    2.06303166975550312,
    3.17887810481605015, // k = 74
    0.99936070171270330,
    2.06257453607466346,
    3.17750067581857820, // k = 75
    0.99936971103502970,
    2.06212696042919674,
    3.17615321728274580, // k = 76
    0.99937847392385493,
    2.06168861430600714,
    3.17483467831510779, // k = 77
    0.99938700168914352,
    2.06125918927764928,
    3.17354405480557489, // k = 78
    0.99939530099953799,
    2.06083838987589729,
    3.17228039269048168, // k = 79
    0.99940338278830154,
    2.06042593411496000,
    3.17104278166036124, // k = 80
    0.99941125463777780,
    2.06002155276328835,
    3.16983035274597569, // k = 81
    0.99941892470027938,
    2.05962498741951094,
    3.16864227952240185, // k = 82
    0.99942640059737187,
    2.05923599161263837,
    3.16747776846497686, // k = 83
    0.99943368842187397,
    2.05885433061945378,
    3.16633606416374391, // k = 84
    0.99944079790603269,
    2.05847977868873500,
    3.16521644518826406, // k = 85
    0.99944773295734990,
    2.05811212058944193,
    3.16411821883858124, // k = 86
    0.99945450059186669,
    2.05775114781260982,
    3.16304072400711789, // k = 87
    0.99946110646314423,
    2.05739666442039493,
    3.16198332650733960, // k = 88
    0.99946755770463369,
    2.05704847678819647,
    3.16094541781455973, // k = 89
    0.99947385746861528,
    2.05670640500335367,
    3.15992641851471490, // k = 90
    0.99948001256305474,
    2.05637027420314666,
    3.15892576988736096, // k = 91
    0.99948602689656241,
    2.05603991286400856,
    3.15794293484717059, // k = 92
    0.99949190674294641,
    2.05571516158917689,
    3.15697740043813724, // k = 93
    0.99949765436329585,
    2.05539586490317561,
    3.15602867309343083, // k = 94
    0.99950327557880314,
    2.05508187237845164,
    3.15509627710042651, // k = 95
    0.99950877461972709,
    2.05477304104951486,
    3.15417975753007340, // k = 96
    0.99951415481862682,
    2.05446923022574879,
    3.15327867462917766, // k = 97
    0.99951942042375208,
    2.05417030908833453,
    3.15239260700215596, // k = 98
    0.99952457390890004,
    2.05387614661762541,
    3.15152114915238712, // k = 99
    0.99952962005008317,
    2.05358662050909402,
    3.15066390921020911, // k = 100
    0.99953456216121594,
    2.05330161104427589,
    3.14982051097524618, // k = 101
    0.99953940176368405,
    2.05302100378725072,
    3.14899059183684926, // k = 102
    0.99954414373920031,
    2.05274468493067275,
    3.14817379948561893, // k = 103
    0.99954879047621148,
    2.05247255013657082,
    3.14736979964868624, // k = 104
    0.99955334485656522,
    2.05220449388099269,
    3.14657826610371671, // k = 105
    0.99955780993869325,
    2.05194041831310869,
    3.14579888316276879, // k = 106
    0.99956218652590678,
    2.05168022402710903,
    3.14503134811607765, // k = 107
    0.99956647932785359,
    2.05142381889103831,
    3.14427536967733090, // k = 108
    0.99957069025060719,
    2.05117111251445294,
    3.14353066260227365, // k = 109
    0.99957482032178291,
    2.05092201793428330,
    3.14279695558593630, // k = 110
    0.99957887261450651,
    2.05067645094720774,
    3.14207398336887422, // k = 111
    0.99958284988383639,
    2.05043432833224415,
    3.14136149076028914, // k = 112
    0.99958675435604505,
    2.05019557189746138,
    3.14065923143530767, // k = 113
    0.99959058650074439,
    2.04996010556124020,
    3.13996696426707445, // k = 114
    0.99959434898201494,
    2.04972785368377686,
    3.13928445867830419, // k = 115
    0.99959804437042976,
    2.04949874512311681,
    3.13861149103462367, // k = 116
    0.99960167394553423,
    2.04927271043337100,
    3.13794784369528656, // k = 117
    0.99960523957651048,
    2.04904968140490951,
    3.13729330661277572, // k = 118
    0.99960874253329735,
    2.04882959397491504,
    3.13664767767019725, // k = 119
    0.99961218434327748,
    2.04861238220240693,
    3.13601075688413289 // k = 120
};

static constexpr double ub_equiv_table[] = {
    1.0,
    2.0,
    3.0, // fake values for k = 0
    0.99067760836669549,
    1.75460517119302040,
    2.48055626001627161, // k = 1
    0.99270518097577565,
    1.78855957509907171,
    2.53863835259832626, // k = 2
    0.99402032633599902,
    1.81047286499563143,
    2.57811676180597260, // k = 3
    0.99492607629539975,
    1.82625928017762362,
    2.60759550546498531, // k = 4
    0.99558653966013821,
    1.83839160339161367,
    2.63086812358551470, // k = 5
    0.99608981951632813,
    1.84812399034444752,
    2.64993712523727254, // k = 6
    0.99648648035983456,
    1.85617372053235385,
    2.66598485907860550, // k = 7
    0.99680750790483330,
    1.86298655802610824,
    2.67976541374471822, // k = 8
    0.99707292880049181,
    1.86885682585270274,
    2.69178781407745760, // k = 9
    0.99729614928489241,
    1.87398826101983218,
    2.70241106542158604, // k = 10
    0.99748667952445658,
    1.87852708449801753,
    2.71189717290596377, // k = 11
    0.99765127712748836,
    1.88258159501103250,
    2.72044290303773550, // k = 12
    0.99779498340305395,
    1.88623391878036273,
    2.72819957382063194, // k = 13
    0.99792160418357412,
    1.88954778748873764,
    2.73528576807902368, // k = 14
    0.99803398604944960,
    1.89257337682371940,
    2.74179612106766513, // k = 15
    0.99813449883217231,
    1.89535099316557876,
    2.74780718300419835, // k = 16
    0.99822494122659577,
    1.89791339232732525,
    2.75338173141955167, // k = 17
    0.99830679915913834,
    1.90028752122407241,
    2.75857186416826039, // k = 18
    0.99838117410831728,
    1.90249575897183831,
    2.76342117562634826, // k = 19
    0.99844913407071090,
    1.90455689090418900,
    2.76796659454200267, // k = 20
    0.99851147736424650,
    1.90648682834171268,
    2.77223944710058845, // k = 21
    0.99856879856019987,
    1.90829917277082473,
    2.77626682032629901, // k = 22
    0.99862183849734265,
    1.91000561415842185,
    2.78007199816156003, // k = 23
    0.99867096266018507,
    1.91161621560812023,
    2.78367524259661536, // k = 24
    0.99871656986212543,
    1.91313978579765376,
    2.78709435016625662, // k = 25
    0.99875907577771272,
    1.91458400425526065,
    2.79034488416175463, // k = 26
    0.99879885565047744,
    1.91595563175945927,
    2.79344064132371273, // k = 27
    0.99883610756373287,
    1.91726064301425936,
    2.79639384757751941, // k = 28
    0.99887095169674467,
    1.91850441099725799,
    2.79921543574803877, // k = 29
    0.99890379414739527,
    1.91969155477030995,
    2.80191513182441554, // k = 30
    0.99893466279047516,
    1.92082633358913313,
    2.80450167352080371, // k = 31
    0.99896392088177777,
    1.92191254955568525,
    2.80698295731653502, // k = 32
    0.99899147889385631,
    1.92295362479495680,
    2.80936614404217266, // k = 33
    0.99901764688726757,
    1.92395267400968351,
    2.81165765979318394, // k = 34
    0.99904238606342233,
    1.92491244978191389,
    2.81386337393604435, // k = 35
    0.99906590152386343,
    1.92583552644848055,
    2.81598868034527072, // k = 36
    0.99908829040739988,
    1.92672418013918900,
    2.81803841726804194, // k = 37
    0.99910959420023460,
    1.92758051694144683,
    2.82001709302821268, // k = 38
    0.99912996403594434,
    1.92840654943159961,
    2.82192875763732332, // k = 39
    0.99914930224576892,
    1.92920397044028391,
    2.82377730628954282, // k = 40
    0.99916781270195543,
    1.92997447498220254,
    2.82556612075063640, // k = 41
    0.99918553179077207,
    1.93071949211818605,
    2.82729843191989971, // k = 42
    0.99920250730914972,
    1.93144048613876862,
    2.82897728689417249, // k = 43
    0.99921873345181211,
    1.93213870990595638,
    2.83060537017752267, // k = 44
    0.99923435180002684,
    1.93281536508689555,
    2.83218527795750674, // k = 45
    0.99924930425362390,
    1.93347145882316340,
    2.83371938965598247, // k = 46
    0.99926370394567243,
    1.93410820221384938,
    2.83520990872793277, // k = 47
    0.99927750755296074,
    1.93472643138986200,
    2.83665891945119597, // k = 48
    0.99929082941537217,
    1.93532697329771963,
    2.83806833931606661, // k = 49
    0.99930366295501472,
    1.93591074716263734,
    2.83943997143404658, // k = 50
    0.99931598804721489,
    1.93647857274021362,
    2.84077557836653227, // k = 51
    0.99932789059798210,
    1.93703110239354714,
    2.84207662106302905, // k = 52
    0.99933946180485123,
    1.93756904936378760,
    2.84334468086129277, // k = 53
    0.99935053819703512,
    1.93809302131219852,
    2.84458116874117195, // k = 54
    0.99936126637970801,
    1.93860365411038060,
    2.84578731838604426, // k = 55
    0.99937166229284458,
    1.93910149816429112,
    2.84696443486512862, // k = 56
    0.99938169190727422,
    1.93958709548454067,
    2.84811369085281285, // k = 57
    0.99939136927613959,
    1.94006085573701625,
    2.84923617230361970, // k = 58
    0.99940074328745254,
    1.94052339623206649,
    2.85033291216254270, // k = 59
    0.99940993070470086,
    1.94097508636855309,
    2.85140492437699322, // k = 60
    0.99941868577388959,
    1.94141633372043998,
    2.85245314430358121, // k = 61
    0.99942734443487780,
    1.94184757038001976,
    2.85347839582286156, // k = 62
    0.99943556385736088,
    1.94226915100517772,
    2.85448160365493209, // k = 63
    0.99944374522542034,
    1.94268143723749631,
    2.85546346373061510, // k = 64
    0.99945159955424856,
    1.94308482059116727,
    2.85642486111805738, // k = 65
    0.99945915301904620,
    1.94347956957849988,
    2.85736639994965458, // k = 66
    0.99946660663832176,
    1.94386600964031686,
    2.85828887832701639, // k = 67
    0.99947383703224091,
    1.94424436597356021,
    2.85919278275500233, // k = 68
    0.99948075442870277,
    1.94461502153473020,
    2.86007887186090670, // k = 69
    0.99948766082269458,
    1.94497821937304138,
    2.86094774077355396, // k = 70
    0.99949422748713346,
    1.94533411296001191,
    2.86179981848076181, // k = 71
    0.99950070756119658,
    1.94568300035135167,
    2.86263579405672886, // k = 72
    0.99950704321753392,
    1.94602523449961495,
    2.86345610449197352, // k = 73
    0.99951320334216121,
    1.94636083782822311,
    2.86426125541271404, // k = 74
    0.99951920293474927,
    1.94669011080745236,
    2.86505169255406145, // k = 75
    0.99952501670378524,
    1.94701327348536779,
    2.86582788270862920, // k = 76
    0.99953071209267819,
    1.94733044372333097,
    2.86659027602854621, // k = 77
    0.99953632734991515,
    1.94764180764266825,
    2.86733927778843167, // k = 78
    0.99954171164873173,
    1.94794766430732125,
    2.86807526143834934, // k = 79
    0.99954699274462655,
    1.94824807472994621,
    2.86879864789403882, // k = 80
    0.99955216611081710,
    1.94854317889829076,
    2.86950970901679625, // k = 81
    0.99955730019613043,
    1.94883320227168610,
    2.87020887436986527, // k = 82
    0.99956213770650493,
    1.94911826561721568,
    2.87089648477021342, // k = 83
    0.99956704264963037,
    1.94939848545763539,
    2.87157281693902178, // k = 84
    0.99957166306481327,
    1.94967401618316671,
    2.87223821840905202, // k = 85
    0.99957632713136491,
    1.94994497791333288,
    2.87289293193450135, // k = 86
    0.99958087233392234,
    1.95021155752212394,
    2.87353731228213860, // k = 87
    0.99958532555996271,
    1.95047376805584349,
    2.87417154907075201, // k = 88
    0.99958956246481989,
    1.95073180380688882,
    2.87479599765507032, // k = 89
    0.99959389351869277,
    1.95098572880579013,
    2.87541081987382086, // k = 90
    0.99959807862052230,
    1.95123574036898617,
    2.87601637401948551, // k = 91
    0.99960214057801977,
    1.95148186921983324,
    2.87661283691068093, // k = 92
    0.99960607527256684,
    1.95172415829728152,
    2.87720042968334155, // k = 93
    0.99960996433179616,
    1.95196280898670693,
    2.87777936649376898, // k = 94
    0.99961379137860717,
    1.95219787713926962,
    2.87834989933620022, // k = 95
    0.99961756088146103,
    1.95242944583677058,
    2.87891216133900230, // k = 96
    0.99962125605327401,
    1.95265762420910960,
    2.87946647367488140, // k = 97
    0.99962486179100551,
    1.95288245314810638,
    2.88001290210658567, // k = 98
    0.99962843240297161,
    1.95310404286672679,
    2.88055166523392359, // k = 99
    0.99963187276145504,
    1.95332251980147475,
    2.88108300006589957, // k = 100
    0.99963525453173929,
    1.95353785898848287,
    2.88160703591438505, // k = 101
    0.99963855412988778,
    1.95375019354571577,
    2.88212393551896184, // k = 102
    0.99964190254169694,
    1.95395953472205974,
    2.88263389761985422, // k = 103
    0.99964506565942202,
    1.95416607430155409,
    2.88313700661564098, // k = 104
    0.99964834424233118,
    1.95436972855640079,
    2.88363350163803034, // k = 105
    0.99965136548857458,
    1.95457068540693513,
    2.88412349413960101, // k = 106
    0.99965436594726498,
    1.95476896383092935,
    2.88460710620208260, // k = 107
    0.99965736463468602,
    1.95496457504532373,
    2.88508450078833789, // k = 108
    0.99966034130443404,
    1.95515761150707590,
    2.88555580586194083, // k = 109
    0.99966326130828520,
    1.95534810382198998,
    2.88602118761679094, // k = 110
    0.99966601446035952,
    1.95553622237747504,
    2.88648066384146773, // k = 111
    0.99966887679593697,
    1.95572186728168163,
    2.88693444915907094, // k = 112
    0.99967161286551232,
    1.95590523410490391,
    2.88738271495714116, // k = 113
    0.99967435412270333,
    1.95608626483223702,
    2.88782540459769166, // k = 114
    0.99967701261934394,
    1.95626497627117146,
    2.88826277189363623, // k = 115
    0.99967963265157778,
    1.95644153684824573,
    2.88869486674335008, // k = 116
    0.99968216317182623,
    1.95661589936000269,
    2.88912184353694101, // k = 117
    0.99968479674396349,
    1.95678821614791332,
    2.88954376359643561, // k = 118
    0.99968729031337489,
    1.95695842061650183,
    2.88996069422501023, // k = 119
    0.99968963358631413,
    1.95712651709766305,
    2.89037285320668502 // k = 120
};

class binomial_bounds {

public:
  static double get_lower_bound(unsigned long long num_samples, double theta,
                                unsigned num_std_devs) {
    check_theta(theta);
    check_num_std_devs(num_std_devs);
    const double estimate = num_samples / theta;
    const double lb =
        compute_approx_binomial_lower_bound(num_samples, theta, num_std_devs);
    return std::min(estimate, std::max(static_cast<double>(num_samples), lb));
  }

  static double get_upper_bound(unsigned long long num_samples, double theta,
                                unsigned num_std_devs) {
    check_theta(theta);
    check_num_std_devs(num_std_devs);
    const double estimate = num_samples / theta;
    const double ub =
        compute_approx_binomial_upper_bound(num_samples, theta, num_std_devs);
    return std::max(estimate, ub);
  }

private:
  // our "classic" bounds, but now with continuity correction
  static double cont_classic_lb(unsigned long long num_samples, double theta,
                                double num_std_devs) {
    const double n_hat = (num_samples - 0.5) / theta;
    const double b = num_std_devs * std::sqrt((1.0 - theta) / theta);
    const double d = 0.5 * b * std::sqrt((b * b) + (4.0 * n_hat));
    const double center = n_hat + (0.5 * (b * b));
    return (center - d);
  }

  // our "classic" bounds, but now with continuity correction
  static double cont_classic_ub(unsigned long long num_samples, double theta,
                                double num_std_devs) {
    const double n_hat = (num_samples + 0.5) / theta;
    const double b = num_std_devs * std::sqrt((1.0 - theta) / theta);
    const double d = 0.5 * b * std::sqrt((b * b) + (4.0 * n_hat));
    const double center = n_hat + (0.5 * (b * b));
    return (center + d);
  }

  // This is a special purpose calculator for NStar, using a computational
  // strategy inspired by its Bayesian definition. It is only appropriate
  // for a very limited set of inputs. However, the procedure
  // compute_approx_binomial_lower_bound() below does in fact only call it for
  // suitably limited inputs. Outside of this limited range, two different bad
  // things will happen. First, because we are not using logarithms, the values
  // of intermediate quantities will exceed the dynamic range of doubles.
  // Second, even if that problem were fixed, the running time of this procedure
  // is essentially linear in est = (numSamples / p), and that can be Very, Very
  // Big.
  static unsigned long long special_n_star(unsigned long long num_samples,
                                           double p, double delta) {
    const double q = 1.0 - p;
    // Use a different algorithm if the following is true; this one will be too
    // slow, or worse.
    if ((num_samples / p) >= 500.0)
      throw std::invalid_argument("out of range");
    double cur_term =
        std::pow(p, num_samples); // curTerm = posteriorProbability (k, k, p)
    if (cur_term <= 1e-100)
      throw std::logic_error(
          "out of range"); // sanity check for non-use of logarithms
    double tot = cur_term;
    unsigned long long m = num_samples;
    while (tot <= delta) { // this test can fail even the first time
      cur_term = (cur_term * q * (m)) / ((m + 1) - num_samples);
      tot += cur_term;
      m += 1;
    }
    // we have reached a state where tot > delta, so back up one
    return (m - 1);
  }

  //  The following procedure has very limited applicability.
  //  The above remarks about special_n_star() also apply here.
  static unsigned long long special_n_prime_b(unsigned long long num_samples,
                                              double p, double delta) {
    const double q = 1.0 - p;
    const double one_minus_delta = 1.0 - delta;
    double cur_term =
        std::pow(p, num_samples); // curTerm = posteriorProbability (k, k, p)
    if (cur_term <= 1e-100)
      throw std::logic_error(
          "out of range"); // sanity check for non-use of logarithms
    double tot = cur_term;
    unsigned long long m = num_samples;
    while (tot < one_minus_delta) {
      cur_term = (cur_term * q * (m)) / ((m + 1) - num_samples);
      tot += cur_term;
      m += 1;
    }
    return m; // no need to back up
  }

  static unsigned long long special_n_prime_f(unsigned long long num_samples,
                                              double p, double delta) {
    // Use a different algorithm if the following is true; this one will be too
    // slow, or worse.
    if ((num_samples / p) >= 500.0)
      throw std::invalid_argument(
          "out of range"); // A super-small delta could also make it slow.
    return special_n_prime_b(num_samples + 1, p, delta);
  }

  // The following computes an approximation to the lower bound of a Frequentist
  // confidence interval based on the tails of the Binomial distribution.
  static double
  compute_approx_binomial_lower_bound(unsigned long long num_samples,
                                      double theta, unsigned num_std_devs) {
    if (theta == 1)
      return static_cast<double>(num_samples);
    if (num_samples == 0)
      return 0;
    if (num_samples == 1) {
      const double delta = delta_of_num_std_devs[num_std_devs];
      const double raw_lb = std::log(1 - delta) / std::log(1 - theta);
      return std::floor(raw_lb); // round down
    }
    if (num_samples > 120) {
      // plenty of samples, so gaussian approximation to binomial distribution
      // isn't too bad
      const double raw_lb = cont_classic_lb(num_samples, theta, num_std_devs);
      return (raw_lb - 0.5); // fake round down
    }
    // at this point we know 2 <= num_samples <= 120
    if (theta > (1 - 1e-5)) { // empirically-determined threshold
      return static_cast<double>(num_samples);
    }
    if (theta < (num_samples / 360.0)) { // empirically-determined threshold
      // here we use the Gaussian approximation, but with a modified
      // num_std_devs
      const unsigned index =
          3 * static_cast<unsigned>(num_samples) + (num_std_devs - 1);
      const double raw_lb =
          cont_classic_lb(num_samples, theta, lb_equiv_table[index]);
      return raw_lb - 0.5; // fake round down
    }
    // This is the most difficult range to approximate; we will compute an
    // "exact" LB. We know that est <= 360, so specialNStar() shouldn't be
    // ridiculously slow.
    const double delta = delta_of_num_std_devs[num_std_devs];
    return static_cast<double>(
        special_n_star(num_samples, theta, delta)); // no need to round
  }

  // The following computes an approximation to the upper bound of a Frequentist
  // confidence interval based on the tails of the Binomial distribution.
  static double
  compute_approx_binomial_upper_bound(unsigned long long num_samples,
                                      double theta, unsigned num_std_devs) {
    if (theta == 1)
      return static_cast<double>(num_samples);
    if (num_samples == 0) {
      const double delta = delta_of_num_std_devs[num_std_devs];
      const double raw_ub = std::log(delta) / std::log(1 - theta);
      return std::ceil(raw_ub); // round up
    }
    if (num_samples > 120) {
      // plenty of samples, so gaussian approximation to binomial distribution
      // isn't too bad
      const double raw_ub = cont_classic_ub(num_samples, theta, num_std_devs);
      return (raw_ub + 0.5); // fake round up
    }
    // at this point we know 2 <= num_samples <= 120
    if (theta > (1 - 1e-5)) { // empirically-determined threshold
      return static_cast<double>(num_samples + 1);
    }
    if (theta < (num_samples / 360.0)) { // empirically-determined threshold
      // here we use the Gaussian approximation, but with a modified
      // num_std_devs
      const unsigned index =
          3 * static_cast<unsigned>(num_samples) + (num_std_devs - 1);
      const double raw_ub =
          cont_classic_ub(num_samples, theta, ub_equiv_table[index]);
      return raw_ub + 0.5; // fake round up
    }
    // This is the most difficult range to approximate; we will compute an
    // "exact" UB. We know that est <= 360, so specialNPrimeF() shouldn't be
    // ridiculously slow.
    const double delta = delta_of_num_std_devs[num_std_devs];
    return static_cast<double>(
        special_n_prime_f(num_samples, theta, delta)); // no need to round
  }

  static void check_theta(double theta) {
    if (theta < 0 || theta > 1) {
      throw std::invalid_argument("theta must be in [0, 1]");
    }
  }

  static void check_num_std_devs(unsigned num_std_devs) {
    if (num_std_devs < 1 || num_std_devs > 3) {
      throw std::invalid_argument("num_std_devs must be 1, 2 or 3");
    }
  }
};

} /* namespace datasketches */

#endif
