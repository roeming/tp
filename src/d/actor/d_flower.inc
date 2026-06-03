#include "d/actor/d_flower.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_player.h"
#include "d/d_s_play.h"
#include "JSystem/J3DGraphBase/J3DDrawBuffer.h"
#include "SSystem/SComponent/c_counter.h"

const u16 l_J_Ohana00_64TEX__width = 63;
const u16 l_J_Ohana00_64TEX__height = 63;
#include "assets/l_J_Ohana00_64TEX.h"

static Vec l_flowerPos[59] = {
    {-4.380488872528076f, 33.434444427490234f, -20.125213623046875f},
    {-0.813746988773346f, 36.58659744262695f, -6.962677001953125f},
    {-8.275179862976074f, 28.690988540649414f, -9.747062683105469f},
    {-17.886348724365234f, 33.374778747558594f, -16.45116424560547f},
    {-14.319605827331543f, 36.52693176269531f, -3.288628101348877f},
    {12.684178352355957f, 23.053672790527344f, -8.357598304748535f},
    {13.60161304473877f, 25.069782257080078f, 1.679710030555725f},
    {7.910160064697266f, 20.685699462890625f, -2.4116289615631104f},
    {3.0826990604400635f, 26.72044563293457f, -8.21649169921875f},
    {4.000133991241455f, 28.73655891418457f, 1.8208160400390625f},
    {-6.184040069580078f, 17.633268356323242f, 13.835585594177246f},
    {-16.413684844970703f, 18.651996612548828f, 9.229415893554688f},
    {-8.698992729187012f, 16.309158325195312f, 5.879767894744873f},
    {-1.7930179834365845f, 23.709810256958008f, 5.427649974822998f},
    {-12.022624015808105f, 24.72853660583496f, 0.8214420080184937f},
    {-18.326446533203125f, 14.710592269897461f, -15.044239044189453f},
    {2.1528310775756836f, 20.227373123168945f, -19.241130828857422f},
    {4.601103782653809f, 18.13783836364746f, -7.9088850021362305f},
    {-15.878173828125f, 12.62105941772461f, -3.7119550704956055f},
    {3.2792320251464844f, 4.284738063812256f, -0.4721989929676056f},
    {-15.04310131072998f, 7.941439151763916f, 11.048416137695312f},
    {-20.185579299926758f, 10.299778938293457f, 1.8271100521087646f},
    {-1.863245964050293f, 6.643077850341797f, -9.693543434143066f},
    {-16.515840530395508f, 7.610645771026611f, 4.778579235076904f},
    {4.740756988525391f, 13.122593879699707f, 5.208763122558594f},
    {3.494610071182251f, 17.136459350585938f, 15.354598999023438f},
    {-17.76198959350586f, 11.624513626098633f, 14.92441463470459f},
    {4.950489044189453f, 9.031510353088379f, 9.714720726013184f},
    {5.415424823760986f, 11.701722145080566f, -12.081199645996094f},
    {15.884785652160645f, 14.958539962768555f, -11.458869934082031f},
    {15.41985034942627f, 12.288328170776367f, 10.337051391601562f},
    {7.0933709144592285f, 20.99443817138672f, -1.809999942779541f},
    {8.638219833374023f, 20.528255462646484f, -2.572972059249878f},
    {-0.007325000129640102f, -10.0f, 0.5879070162773132f},
    {-0.06671600043773651f, -10.0f, 0.6166390180587769f},
    {7.545481204986572f, 20.783525466918945f, -2.85384202003479f},
    {8.18642807006836f, 20.739185333251953f, -1.5289700031280518f},
    {-0.025442000478506088f, -10.0f, 0.6260700225830078f},
    {-0.04871499910950661f, -9.999999046325684f, 0.5789470076560974f},
    {-7.831759929656982f, 16.719587326049805f, 5.3407511711120605f},
    {-9.010233879089355f, 16.07769775390625f, 6.5149922370910645f},
    {0.3792380094528198f, -10.0f, 0.6630859971046448f},
    {0.720786988735199f, -9.999999046325684f, 0.34366101026535034f},
    {-7.920146942138672f, 16.458782196044922f, 6.463341236114502f},
    {-8.92154312133789f, 16.3385066986084f, 5.392592906951904f},
    {0.42408299446105957f, -10.0f, 0.3738729953765869f},
    {0.6789510250091553f, -10.0f, 0.6296579837799072f},
    {-7.777359962463379f, 29.03676414489746f, -9.263213157653809f},
    {-8.781164169311523f, 28.571908950805664f, -10.254602432250977f},
    {-2.017896890640259f, -10.0f, 1.421241044998169f},
    {-1.9239269495010376f, -9.999998092651367f, 1.5192619562149048f},
    {-8.712038040161133f, 28.81474494934082f, -9.325393676757812f},
    {-7.846244812011719f, 28.793954849243164f, -10.192313194274902f},
    {-1.932953953742981f, -10.0f, 1.4326289892196655f},
    {-2.0080320835113525f, -10.000000953674316f, 1.5086239576339722f},
    {-6.31400203704834f, 19.277572631835938f, -6.567594051361084f},
    {-7.090346813201904f, 18.928930282592773f, -7.335640907287598f},
    {-7.036036968231201f, 19.111059188842773f, -6.616888999938965f},
    {-6.367921829223633f, 19.09546661376953f, -7.286077976226807f},
};

static Vec l_flowerNormal[15] = {
    {0.017232999205589294f, 0.9998469948768616f, 0.0030360000673681498f},
    {0.01504599954932928f, 0.9998469948768616f, 0.008933999575674534f},
    {-0.007007999811321497f, 0.9998469948768616f, 0.016032999381422997f},
    {0.007619999814778566f, 0.9998469948768616f, 0.015752000734210014f},
    {-0.015689000487327576f, 0.9998469948768616f, 0.007747999858111143f},
    {-0.011958000250160694f, 0.9998469948768616f, -0.012775000184774399f},
    {0.012400999665260315f, 0.9998469948768616f, -0.01234500017017126f},
    {0.012636999599635601f, 0.9998469948768616f, -0.012102999724447727f},
    {0.01244799979031086f, 0.9998469948768616f, 0.012298000045120716f},
    {0.017232000827789307f, 0.9998469948768616f, 0.00304200011305511f},
    {-0.01568800024688244f, 0.9998469948768616f, 0.00774999987334013f},
    {-0.011962000280618668f, 0.9998469948768616f, -0.012771000154316425f},
    {0.012404999695718288f, 0.9998469948768616f, -0.012341000139713287f},
    {0.012636000290513039f, 0.9998469948768616f, -0.012105000205338001f},
    {0.012446999549865723f, 0.9998469948768616f, 0.012299000285565853f},
};

static GXColor l_flowerColor[2] = {
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xB2, 0xB2, 0xB2, 0xFF},
};

static f32 l_flowerTexCoord[][2] = {
    {3.0127511024475098f, 0.056992001831531525f},
    {3.966320037841797f, 1.0096980333328247f},
    {3.0126049518585205f, 1.0096980333328247f},
    {2.029125928878784f, 1.0096980333328247f},
    {3.0127511024475098f, 1.9474740028381348f},
    {2.0125560760498047f, -0.9993320107460022f},
    {3.011888027191162f, 0.0f},
    {2.5122220516204834f, 0.4996660053730011f},
    {1.5128899812698364f, -0.4996660053730011f},
    {2.0125560760498047f, 0.9993320107460022f},
    {1.0132240056991577f, 0.0f},
    {0.04918399825692177f, -0.12222199887037277f},
    {0.012972000055015087f, -0.12222199887037277f},
    {0.030337000265717506f, -0.6543769836425781f},
    {0.03162899985909462f, -0.6546649932861328f},
    {-0.04789799824357033f, -0.12342000007629395f},
    {-0.0072639998979866505f, -0.12342000007629395f},
    {-0.02979999966919422f, -0.6545510292053223f},
    {-0.03125f, -0.6545789837837219f},
    {-0.12827500700950623f, -0.05646900087594986f},
    {-0.12827500700950623f, -0.015967000275850296f},
    {-0.645268976688385f, -0.032850999385118484f},
    {-0.6483520269393921f, -0.04276600107550621f},
    {-0.12827099859714508f, 0.04701099917292595f},
    {-0.12827099859714508f, 0.005367999896407127f},
    {-0.6472669839859009f, 0.019348999485373497f},
    {-0.647845983505249f, 0.02952899970114231f},
    {0.15313899517059326f, 0.04464399814605713f},
    {0.15313899517059326f, 0.0030580000020563602f},
    {0.8484249711036682f, 0.02702300064265728f},
    {0.8491510152816772f, 0.03064900077879429f},
    {0.15313899517059326f, -0.007199999876320362f},
    {0.15313899517059326f, -0.04878599941730499f},
    {0.8487740159034729f, -0.024809999391436577f},
    {0.8488069772720337f, -0.021189000457525253f},
    {0.32714200019836426f, 0.041145000606775284f},
    {0.3269599974155426f, 0.009050000458955765f},
    {0.32705599069595337f, -0.010697999969124794f},
    {0.32704800367355347f, -0.042791999876499176f},
};

#include "assets/l_J_hana00DL.h"

#include "assets/l_J_hana00_cDL.h"

#include "assets/l_matDL__d_a_grass.h"
l_matDL__d_a_grass(l_J_Ohana00_64TEX)

#include "assets/l_matLight4DL.h"
l_matLight4DL(l_J_Ohana00_64TEX)

const u16 l_J_Ohana01_64128_0419TEX__width = 63;
const u16 l_J_Ohana01_64128_0419TEX__height = 127;
#include "assets/l_J_Ohana01_64128_0419TEX.h"

static Vec l_flowerPos2[102] = {
    {2.5878419876098633f, 97.29188537597656f, -10.137809753417969f},
    {12.873385429382324f, 137.2072296142578f, 4.745035171508789f},
    {15.406331062316895f, 93.05606079101562f, 18.155298233032227f},
    {-4.798495769500732f, 97.27725982666016f, 9.164323806762695f},
    {23.138181686401367f, 93.1091537475586f, -1.4829909801483154f},
    {12.873340606689453f, 137.20726013183594f, 4.744959831237793f},
    {-8.442581176757812f, 102.3105239868164f, -12.139052391052246f},
    {-6.051340103149414f, 148.8739471435547f, 6.545639991760254f},
    {2.796786069869995f, 99.58139038085938f, 19.756240844726562f},
    {-6.051376819610596f, 148.8739471435547f, 6.545599937438965f},
    {-18.710729598999023f, 98.09754180908203f, 9.670294761657715f},
    {13.064860343933105f, 103.79444122314453f, -2.053107976913452f},
    {-8.098981857299805f, 89.70753479003906f, -17.41216468811035f},
    {-6.64521598815918f, 127.2413330078125f, -8.64443302154541f},
    {2.451237916946411f, 97.08843231201172f, 8.415589332580566f},
    {-15.715681076049805f, 92.2140121459961f, 0.8546850085258484f},
    {10.067859649658203f, 94.58201599121094f, -9.851373672485352f},
    {-6.645254135131836f, 127.2413558959961f, -8.644509315490723f},
    {8.402584075927734f, 98.0715103149414f, 3.9413390159606934f},
    {10.257218360900879f, 97.91903686523438f, 3.9413390159606934f},
    {1.829306960105896f, -10.0f, 0.16150499880313873f},
    {-1.0863879919052124f, -10.000000953674316f, 0.15316200256347656f},
    {9.332560539245605f, 98.02761840820312f, 3.011460065841675f},
    {9.327240943908691f, 97.962890625f, 4.871218204498291f},
    {0.37258899211883545f, -10.0f, 1.610617995262146f},
    {0.372516006231308f, -9.999999046325684f, -1.2968690395355225f},
    {-3.675442934036255f, 96.61975860595703f, -5.025092124938965f},
    {-1.7259639501571655f, 96.66545104980469f, -5.013215065002441f},
    {1.0687309503555298f, -9.999999046325684f, -0.6422690153121948f},
    {-1.5070199966430664f, -10.000000953674316f, -0.660286009311676f},
    {-2.6939940452575684f, 96.6060562133789f, -5.9933881759643555f},
    {-2.707408905029297f, 96.67911529541016f, -4.044916152954102f},
    {-0.2269739955663681f, -10.0f, 0.6373569965362549f},
    {-0.21173399686813354f, -10.000000953674316f, -1.9392529726028442f},
    {-3.8985629081726074f, 104.27909851074219f, 3.9413390159606934f},
    {-2.0028159618377686f, 104.32362365722656f, 3.9413390159606934f},
    {0.6837210059165955f, -9.972173690795898f, -0.005338999908417463f},
    {-1.685763955116272f, -10.027828216552734f, -0.005338999908417463f},
    {-2.9514079093933105f, 104.3341293334961f, 2.9937191009521484f},
    {-2.949971914291382f, 104.26860046386719f, 4.888957977294922f},
    {-0.500124990940094f, -10.0409517288208f, 1.1790859699249268f},
    {-0.5019180178642273f, -9.959050178527832f, -1.1897640228271484f},
    {5.9237799644470215f, 56.98748779296875f, 2.5521280765533447f},
    {14.324163436889648f, 93.50135040283203f, -17.509021759033203f},
    {25.29817008972168f, 93.5013427734375f, 10.543232917785645f},
    {-13.72816276550293f, 93.50132751464844f, -6.534976005554199f},
    {-2.7541959285736084f, 93.5013198852539f, 21.51723861694336f},
    {-1.3592089414596558f, 22.071828842163086f, 1.0408209562301636f},
    {19.896398544311523f, 72.31130981445312f, -17.315120697021484f},
    {15.694395065307617f, 72.3113021850586f, 20.993938446044922f},
    {-9.23710823059082f, 72.31131744384766f, -18.26578140258789f},
    {-15.991192817687988f, 72.31131744384766f, 12.4266357421875f},
    {-0.6437190175056458f, 49.23548126220703f, -2.936203956604004f},
    {-2.831286907196045f, 49.217529296875f, -2.950814962387085f},
    {-1.7444599866867065f, 49.2408561706543f, -1.849503993988037f},
    {-1.7307770252227783f, 49.2121467590332f, -4.037149906158447f},
    {-0.7899010181427002f, 53.525943756103516f, 2.1872599124908447f},
    {-2.933995008468628f, 53.47557830810547f, 2.1872589588165283f},
    {-1.86113703250885f, 53.46371078491211f, 3.259018898010254f},
    {-1.8627599477767944f, 53.53781509399414f, 1.1154999732971191f},
    {5.993058204650879f, 71.04048156738281f, 2.99379301071167f},
    {8.187522888183594f, 70.95242309570312f, 2.997006893157959f},
    {7.092234134674072f, 71.01513671875f, 1.8980909585952759f},
    {7.089189052581787f, 70.9777603149414f, 4.092353820800781f},
    {-0.30492299795150757f, 32.028724670410156f, -6.595539093017578f},
    {10.86599063873291f, 32.028717041015625f, -6.2779388427734375f},
    {2.3637490272521973f, 19.23622703552246f, 1.0644370317459106f},
    {9.18519115447998f, 32.02871322631836f, 9.045683860778809f},
    {-3.0065550804138184f, 32.028717041015625f, 5.681427001953125f},
    {5.507306098937988f, 34.1243896484375f, 5.620707988739014f},
    {-3.931401014328003f, 34.124385833740234f, 11.60410213470459f},
    {-0.9885269999504089f, 22.62056541442871f, 0.7626039981842041f},
    {-11.106815338134766f, 34.12438201904297f, -2.03964900970459f},
    {0.8818690180778503f, 34.124385833740234f, -6.068090915679932f},
    {-5.738922119140625f, 32.93495178222656f, -7.786919116973877f},
    {4.748826026916504f, 32.9349479675293f, -11.646623611450195f},
    {-0.41288700699806213f, 19.236228942871094f, -1.6688820123672485f},
    {8.88752555847168f, 32.934940338134766f, 3.2029449939727783f},
    {-0.1618649959564209f, 34.40620803833008f, -2.0896871089935303f},
    {1.0578030347824097f, -9.897748947143555f, -0.6357020139694214f},
    {-1.4916110038757324f, -9.897750854492188f, -0.653535008430481f},
    {-2.1955690383911133f, 34.39705276489258f, -2.103559970855713f},
    {-1.1850559711456299f, 34.40895080566406f, -1.0793880224227905f},
    {-0.22465300559997559f, -9.897748947143555f, 0.630840003490448f},
    {-0.20956900715827942f, -9.897750854492188f, -1.919424057006836f},
    {-1.1726449728012085f, 34.39430236816406f, -3.1134378910064697f},
    {-0.3494409918785095f, 34.328521728515625f, 1.3836300373077393f},
    {0.6767299771308899f, -9.870207786560059f, -0.005284999962896109f},
    {-1.6685270071029663f, -9.92529296875f, -0.005284999962896109f},
    {-2.366529941558838f, 34.2811393737793f, 1.3836300373077393f},
    {-1.3572219610214233f, 34.26997756958008f, 2.3919050693511963f},
    {-0.49501100182533264f, -9.938282012939453f, 1.1670290231704712f},
    {-0.4967859983444214f, -9.857217788696289f, -1.177597999572754f},
    {-1.3587490320205688f, 34.339691162109375f, 0.375355988740921f},
    {2.4711549282073975f, 32.5742301940918f, 1.5013949871063232f},
    {4.6482930183410645f, 32.547088623046875f, 1.5066800117492676f},
    {1.8106019496917725f, -9.897748947143555f, 0.159852996468544f},
    {-1.0752789974212646f, -9.897750854492188f, 0.15159599483013153f},
    {3.5608670711517334f, 32.5664176940918f, 0.41732099652290344f},
    {3.5599660873413086f, 32.55489730834961f, 2.590172052383423f},
    {0.3687790036201477f, -9.897748947143555f, 1.5941489934921265f},
    {0.36870700120925903f, -9.897747993469238f, -1.2836090326309204f},
};

static Vec l_flowerNormal2[24] = {
    {-0.005998999811708927f, 0.9998540282249451f, -0.015998000279068947f},
    {0.01599700003862381f, 0.9998400211334229f, 0.007999000139534473f},
    {-4.999999873689376e-05f, 0.9998469948768616f, 0.017497999593615532f},
    {-0.017497999593615532f, 0.9998469948768616f, 3.7999998312443495e-05f},
    {-0.09022899717092514f, 0.9937779903411865f, -0.06530299782752991f},
    {-0.10615099966526031f, 0.9927989840507507f, -0.05551400035619736f},
    {-0.08987899869680405f, 0.9938210248947144f, -0.06512899696826935f},
    {-0.12362200021743774f, 0.9896270036697388f, -0.07318799942731857f},
    {-0.0887570008635521f, 0.9960219860076904f, 0.007921000011265278f},
    {-0.00012199999764561653f, 0.9998469948768616f, 0.017497999593615532f},
    {1.1000000085914508e-05f, 0.9998469948768616f, -0.017497999593615532f},
    {-0.017497999593615532f, 0.9998469948768616f, -9.100000170292333e-05f},
    {3.199999991920777e-05f, 0.9998469948768616f, -0.017497999593615532f},
    {1.4000000192027073e-05f, 0.9998469948768616f, 0.017497999593615532f},
    {-0.01742899976670742f, 0.9998469948768616f, 0.0015559999737888575f},
    {-0.017497999593615532f, 0.9998469948768616f, 0.0f},
    {-0.017497999593615532f, 0.9998469948768616f, -2.499999936844688e-05f},
    {-0.017496999353170395f, 0.9998469948768616f, 0.00019700000120792538f},
    {-0.0004970000009052455f, 0.9998469948768616f, 0.017490999773144722f},
    {0.015650000423192978f, 0.9998469948768616f, 0.007826999761164188f},
    {-0.017395000904798508f, 0.9998469948768616f, -0.0018990000244230032f},
    {0.0046640001237392426f, 0.9998469948768616f, -0.016865000128746033f},
    {0.0170889999717474f, 0.9998469948768616f, 0.0037609999999403954f},
    {0.004681999795138836f, 0.9998469948768616f, -0.016860000789165497f},
};

static GXColor l_flowerColor2[2] = {
    {0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xB2, 0xFF},
};

static f32 l_flowerTexCoord2[36][2] = {
    {1.9017659425735474f, 0.9454900026321411f},  {1.0f, 0.020979000255465508f},
    {0.09823399782180786f, 0.9454900026321411f}, {2.6808838844299316f, 1.0115840435028076f},
    {2.6808838844299316f, 0.9832320213317871f},  {2.095690965652466f, 0.9832320213317871f},
    {2.093766927719116f, 1.0115840435028076f},   {2.0951380729675293f, 1.0115840435028076f},
    {2.0943210124969482f, 0.9832320213317871f},  {2.120795965194702f, 0.9832320213317871f},
    {2.121274948120117f, 1.0115840435028076f},   {2.120651960372925f, 1.0115840435028076f},
    {2.121417999267578f, 0.9832320213317871f},   {2.057210922241211f, 0.9832320213317871f},
    {2.057210922241211f, 1.0115840435028076f},   {2.0075509548187256f, -5.018998146057129f},
    {2.890692949295044f, -5.91077995300293f},    {2.0075509548187256f, -5.939184188842773f},
    {2.0075509548187256f, -5.91077995300293f},   {2.5911641120910645f, 0.9832320213317871f},
    {2.591377019882202f, 1.0115840435028076f},   {2.591099977493286f, 1.0115840435028076f},
    {2.5914409160614014f, 0.9832320213317871f},  {2.562903881072998f, 0.9832320213317871f},
    {2.562903881072998f, 1.0115840435028076f},   {2.7490360736846924f, 1.0115840435028076f},
    {2.7495169639587402f, 0.9832320213317871f},  {2.749174118041992f, 0.9832320213317871f},
    {2.749377965927124f, 1.0115840435028076f},   {3.6053109169006348f, 0.8166570067405701f},
    {3.6053109169006348f, 1.1872169971466064f},  {3.939068078994751f, 1.002879023551941f},
    {2.4295239448547363f, 1.1872169971466064f},  {2.064846992492676f, 1.0019370317459106f},
    {2.4295239448547363f, 1.0019370317459106f},  {2.4295239448547363f, 0.8166570067405701f},
};

#include "assets/l_J_hana01DL.h"

#include "assets/l_J_hana01_c_00DL.h"

#include "assets/l_J_hana01_c_01DL.h"

#include "assets/l_mat2DL__d_a_grass.h"
l_mat2DL__d_a_grass(l_J_Ohana01_64128_0419TEX)

#include "assets/l_mat2Light4DL.h"
l_mat2Light4DL(l_J_Ohana01_64128_0419TEX)

void dFlower_data_c::WorkCo(fopAc_ac_c* i_hitActor, u32 i_massFlg, int i_roomNo) {
    cXyz sp8;
    sp8.x = m_pos.x - i_hitActor->current.pos.x;
    sp8.z = m_pos.z - i_hitActor->current.pos.z;

    f32 temp_f1 = sp8.abs2XZ();
    if (!(temp_f1 > 900.0f)) {
        sp8.y = m_pos.y - i_hitActor->current.pos.y;

        s16 temp_r26 = cM_atan2s(sp8.x, sp8.z);
        f32 var_f31 = JMAFastSqrt(temp_f1);

        dFlower_anm_c* var_r29;
        if (field_0x01 < 8) {
            int temp_r3_2 = daGrass_c::getFlower()->newAnm();
            if (temp_r3_2 < 0) {
                return;
            }

            field_0x01 = temp_r3_2;
            var_r29 = daGrass_c::getFlower()->getAnm(field_0x01);
        } else {
            var_r29 = daGrass_c::getFlower()->getAnm(field_0x01);
        }

        var_r29->m_angY = temp_r26;
        var_r29->m_angX = cM_atan2s(30.0f -  var_f31, 65.0f);
    }
}

void dFlower_data_c::deleteAnm() {
    if (field_0x01 >= 8) {
        daGrass_c::getFlower()->deleteAnm(field_0x01);
        dFlower_anm_c* anm_p = daGrass_c::getFlower()->getAnm(field_0x01);
        field_0x01 = (anm_p->m_angY >> 0xD) & 7;
    }
}

void dFlower_data_c::WorkAt_NoCutAnim(fopAc_ac_c* i_hitActor, u32 i_massFlg, int i_roomNo,
                                      dCcMassS_HitInf* i_hitinf, cCcD_Obj* i_hitobj) {
    dCcD_GObjInf* var_r26 = dCcD_GetGObjInf(i_hitobj);
    cXyz sp14(*var_r26->GetAtVecP());

    f32 temp_f31 = sp14.abs2XZ();
    if (cM3d_IsZero(temp_f31) && fopAcM_GetName(i_hitActor) == fpcNm_ALINK_e) {
        sp14.x = m_pos.x - i_hitActor->current.pos.x;
        sp14.y = m_pos.y - i_hitActor->current.pos.y;
        sp14.z = m_pos.z - i_hitActor->current.pos.z;
        temp_f31 = sp14.abs2XZ();
    }

    temp_f31 = sp14.abs2XZ();

    s16 temp_r25 = cM_atan2s(sp14.x, sp14.z);
    temp_f31 = JMAFastSqrt(temp_f31);

    dFlower_anm_c* var_r29;
    if (field_0x01 < 8) {
        int temp_r3_2 = daGrass_c::getFlower()->newAnm();
        if (temp_r3_2 < 0) {
           return; 
        }
        field_0x01 = temp_r3_2;
        var_r29 = daGrass_c::getFlower()->getAnm(field_0x01);
    } else {
        var_r29 = daGrass_c::getFlower()->getAnm(field_0x01);
    }

    var_r29->m_angY = temp_r25;
    var_r29->m_angX = cM_atan2s(temp_f31, 220.0f);
}

static bool data_805284E8;

void dFlower_data_c::WorkAt(fopAc_ac_c* i_hitActor, u32 i_massFlg, int i_roomNo, dCcMassS_HitInf* i_hitinf) {
    cCcD_Obj* hitobj_p = i_hitinf->GetAtHitObj();

    if (hitobj_p != NULL &&
        (hitobj_p->ChkAtType(0) || hitobj_p->ChkAtType(AT_TYPE_ARROW) || hitobj_p->ChkAtType(AT_TYPE_SLINGSHOT) ||
         hitobj_p->ChkAtType(AT_TYPE_20000000) || hitobj_p->ChkAtType(AT_TYPE_SHIELD_ATTACK) ||
         hitobj_p->ChkAtType(AT_TYPE_BOOMERANG) || hitobj_p->ChkAtType(AT_TYPE_100) ||
         hitobj_p->ChkAtType(AT_TYPE_LANTERN_SWING) || hitobj_p->ChkAtType(AT_TYPE_HOOKSHOT)))
    {
        WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hitobj_p);
        return;
    }

    if (field_0x03 == 0) {
        fopAc_ac_c* temp_r26 = dComIfGp_getPlayer(0);
        if (hitobj_p->ChkAtType(AT_TYPE_BOMB) || hitobj_p->ChkAtType(AT_TYPE_IRON_BALL) ||
            hitobj_p->ChkAtType(AT_TYPE_SPINNER) || hitobj_p->ChkAtType(AT_TYPE_WOLF_ATTACK) ||
            hitobj_p->ChkAtType(AT_TYPE_WOLF_CUT_TURN))
        {
            if (i_hitActor != NULL && !hitobj_p->ChkAtType(AT_TYPE_IRON_BALL) && m_pos.abs(i_hitActor->current.pos) > 200.0f) {
                WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hitobj_p);
                return;
            }
        } else {
            if (cLib_checkBit<u8>(m_state, 0x10) || !cLib_checkBit<u8>(m_state, 0x40)) {
                if ((daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_NM_VERTICAL) ||
                    (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_NM_STAB) ||
                    (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_RIGHT) ||
                    (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_LEFT) ||
                    (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_RIGHT) ||
                    (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_LEFT))
                {
                    if (m_pos.abs(temp_r26->current.pos) > 180.0f) {
                        WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hitobj_p);
                        return;
                    }
                } else {
                    WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hitobj_p);
                    return;
                }
            } 
            
            if ((daPy_getPlayerActorClass()->getCutType() >= daPy_py_c::CUT_TYPE_NM_RIGHT) && (daPy_getPlayerActorClass()->getCutType() <= daPy_py_c::CUT_TYPE_FINISH_VERTICAL)) {
                if (m_pos.abs(temp_r26->current.pos) > 128.0f) {
                    if (m_pos.abs(temp_r26->current.pos) < 200.0f) {
                        WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hitobj_p);
                    }
                    return;
                }
            } else if ((daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_RIGHT) ||
                (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_LEFT) ||
                (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_RIGHT) ||
                (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_LEFT))
            {
                if (m_pos.abs(temp_r26->current.pos) > 150.0f) {
                    WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hitobj_p);
                    return;
                }
            } else if ((daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_NM_VERTICAL) || (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_NM_STAB)) {
                if (m_pos.abs(temp_r26->current.pos) > 80.0f) {
                    return;
                }
            } else if ((m_pos.abs(i_hitActor->current.pos) > 128.0f) && (m_pos.abs(temp_r26->current.pos) < 200.0f)) {
                WorkAt_NoCutAnim(i_hitActor, i_massFlg, i_roomNo, i_hitinf, hitobj_p);
                return;
            }
        }

        if (field_0x01 >= 8) {
            deleteAnm();
        }

        if (cLib_checkBit<u8>(m_state, 0x40)) {
            if (hitobj_p->ChkAtType(AT_TYPE_BOMB) || hitobj_p->ChkAtType(AT_TYPE_IRON_BALL) ||
                hitobj_p->ChkAtType(AT_TYPE_SPINNER) || hitobj_p->ChkAtType(AT_TYPE_WOLF_ATTACK) ||
                hitobj_p->ChkAtType(AT_TYPE_WOLF_CUT_TURN) ||
                (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_RIGHT) ||
                (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_TURN_LEFT) ||
                (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_RIGHT) ||
                (daPy_getPlayerActorClass()->getCutType() == daPy_py_c::CUT_TYPE_LARGE_TURN_LEFT))
            {
                cLib_onBit<u8>(m_state, 8);
            } else if (cLib_checkBit<u8>(m_state, 0x10)) {
                cLib_onBit<u8>(m_state, 8);
            } else {
                field_0x03 = 0x14;
                cLib_onBit<u8>(m_state, 0x10);
            }
        } else {
            cLib_onBit<u8>(m_state, 8);
        }

        static csXyz ang(0, 0, 0);

        cXyz particle_pos;
        dKy_tevstr_c* room_tevstr = dComIfGp_roomControl_getTevStr(i_roomNo);

        particle_pos.set(m_pos.x, m_pos.y, m_pos.z);

        if (cLib_checkBit<u8>(m_state, 0x40)) {
            dComIfGp_particle_set(0x8297, &particle_pos, room_tevstr, NULL, NULL);
            dComIfGp_particle_set(0x8298, &particle_pos, room_tevstr, NULL, NULL);
        } else {
            dComIfGp_particle_set(0x8299, &particle_pos, room_tevstr, NULL, NULL);
            dComIfGp_particle_set(0x829A, &particle_pos, room_tevstr, NULL, NULL);
        }

        if (m_tableNo >= 0) {
            fopAcM_createItemFromTable(&m_pos, m_tableNo, -1, i_roomNo, NULL, 0, NULL, NULL, NULL, false);
        }

        if (data_805284E8 == 0) {
            data_805284E8 = 1;
            mDoAud_seStart(JA_SE_LK_CUT_GRASS, &m_pos, 0, dComIfGp_getReverb(i_roomNo));
        }
    }
}

void dFlower_data_c::hitCheck(fopAc_ac_c* i_hitActor, int i_roomNo) {
    dCcMassS_HitInf hitinf;

    cXyz sp14;
    sp14 = m_pos;

    if (cLib_checkBit<u8>(m_state, 0x40)) {
        sp14.y += 60.0f;
    }

    fopAc_ac_c* hit_actor;
    u32 mass_flags = dComIfG_Ccsp()->ChkMass(&sp14, &hit_actor, &hitinf);
    bool at_hit = (mass_flags & 1) && (hit_actor != NULL && fopAcM_GetName(hit_actor) != fpcNm_Obj_Carry_e);

    if (!(mass_flags & 2) && !at_hit) {
        if (field_0x01 >= 8) {
            dFlower_anm_c* temp_r3 = daGrass_c::getFlower()->getAnm(field_0x01);
            s16 spA = (temp_r3->m_angY & 0xE000);
            int spC = (temp_r3->m_angY >> 0xD) & 7;

            if (cLib_addCalcAngleS(&temp_r3->m_angX, daGrass_c::getFlower()->getAnm(spC)->m_angX, 8, 4000, 100) == 0 &&
                cLib_chaseAngleS(&temp_r3->m_angY, spA, 800) != 0) {
                deleteAnm();
            }
        }
    } else {
        if (mass_flags & 2) {
            WorkCo(hit_actor, mass_flags, i_roomNo);
        }

        if (!cLib_checkBit<u8>(m_state, 8) && at_hit) {
            WorkAt(hit_actor, mass_flags, i_roomNo, &hitinf);
        }
    }
}

void dFlower_room_c::newData(dFlower_data_c* i_data) {
    i_data->mp_next = mp_data;
    mp_data = i_data;
}

void dFlower_room_c::deleteData() {
    while (mp_data != NULL) {
        mp_data->deleteAnm();
        mp_data->m_state = 0;
        mp_data = mp_data->mp_next;
    }
}

dFlower_packet_c::dFlower_packet_c() {
    dFlower_data_c* data_p = m_data;
    for (int i = 0; i < 1000; i++) {
        data_p->m_state = 0;
        data_p++;
    }

    dFlower_anm_c* anm_p = m_anm;
    for (int i = 0; i < 72; i++) {
        anm_p->m_state = 0;
        anm_p++;
    }

    s16 unused = 0;
    for (int i = 0; i < 8; i++) {
        setAnm(i, unused);
        unused += 0x2000;
    }

    m_deleteRoom = &dFlower_packet_c::deleteRoom;
}

void dFlower_packet_c::draw() {
    dScnKy_env_light_c* kankyo = dKy_getEnvlight();
    j3dSys.reinitGX();

    GXSetNumIndStages(0);
    dKy_setLight_again();
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
    GXSetVtxDesc(GX_VA_NRM, GX_INDEX8);
    GXSetVtxDesc(GX_VA_CLR0, GX_INDEX8);
    GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_NRM, GX_NRM_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetArray(GX_VA_POS, &l_flowerPos, sizeof(cXyz));
    GXSetArray(GX_VA_NRM, &l_flowerNormal, sizeof(cXyz));
    GXSetArray(GX_VA_CLR0, &l_flowerColor, sizeof(GXColor));
    GXSetArray(GX_VA_TEX0, &l_flowerTexCoord, sizeof(f32[2]));

    GXColor sp64;
    dFlower_room_c* sp5C = m_room;

    for (int i = 0; i < 64; i++) {
        dFlower_data_c* sp54 = sp5C->getData();
        if (sp54 != NULL && dComIfGp_roomControl_checkStatusFlag(i, 0x10)) {
            dKy_tevstr_c* sp50 = dComIfGp_roomControl_getTevStr(i);
            GXColorS10 sp80 = {0, 0, 0, 0};
            int sp84 = 0;
            int sp4C = 6;

            if (dComIfGp_roomControl_getStatusRoomDt(i) != NULL) {
                sp4C = dComIfGp_roomControl_getStatusRoomDt(i)->getLightVecInfoNum();
            }

            if (dKy_SunMoon_Light_Check() == TRUE && sp4C < 2) {
                sp4C = 2;
            }

            for (int j = 0; j < 6; j++) {
                if (kankyo->field_0x0c18[j].field_0x26 == 1) {
                    sp4C++;
                }
            }

            if (sp4C <= 2) {
                GXCallDisplayList(&l_matLight4DL, 0x80);
            } else {
                GXCallDisplayList(&l_matDL, 0x80);
            }

            GXSetTevColorS10(GX_TEVREG0, sp80);
            dKy_Global_amb_set(sp50);
            dKy_GxFog_tevstr_set(sp50);
            dKy_setLight_nowroom_grass(sp50->room_no, 1.0f);

            for (dFlower_data_c* sp44 = sp5C->getData(); sp44 != NULL; sp44 = sp44->mp_next) {
                if (DEBUG && g_kankyoHIO.navy.grass_adjust_ON != 0) {
                    sp64.r = g_kankyoHIO.navy.grass_ambcol.r * 2;
                    sp64.g = g_kankyoHIO.navy.grass_ambcol.g * 2;
                    sp64.b = g_kankyoHIO.navy.grass_ambcol.b * 2;
                } else {
                    sp64.r = (sp44->field_0x04 & 0x1F) * 2;
                    sp64.g = ((sp44->field_0x04 >> 5) & 0x1F) * 2;
                    sp64.b = ((sp44->field_0x04 >> 0xA) & 0x1F) * 2;
                }

                if (daPy_py_c::checkNowWolfPowerUp()) {
                    f32 var_f31 = g_env_light.bg_amb_col[0].r / 255.0f;
                    f32 var_f1 = (((sp44->field_0x04 & 0x1F) * 2 + 0x10));
                    sp64.r = var_f1 * (var_f31 * 4.0f);

                    var_f31 = g_env_light.bg_amb_col[0].g / 255.0f;
                    f32 var_f1_2 = (((sp44->field_0x04 >> 5) & 0x1F) * 2 + 0x10);
                    sp64.g = var_f1_2 * (4.0f * var_f31);

                    var_f31 = g_env_light.bg_amb_col[0].b / 255.0f;
                    f32 var_f1_3 = (((sp44->field_0x04 >> 10) & 0x1F) * 2 + 0x10);
                    sp64.b = var_f1_3 * (4.0f * var_f31);
                }

                if (sp64.r == 0x3E) {
                    sp64.r = sp50->AmbCol.r;
                }

                if (sp64.g == 0x3E) {
                    sp64.g = sp50->AmbCol.g;
                }

                if (sp64.b == 0x3E) {
                    sp64.b = sp50->AmbCol.b;
                }

                GXSetChanAmbColor(GX_COLOR0A0, sp64);

                if (!cLib_checkBit<u8>(sp44->m_state, 4) && !cLib_checkBit<u8>(sp44->m_state, 0x40)) {
                    GXLoadPosMtxImm(sp44->m_modelMtx, 0);
                    GXLoadNrmMtxImm(j3dSys.getViewMtx(), 0);

                    if (!cLib_checkBit<u8>(sp44->m_state, 8)) {
                        GXCallDisplayList(&l_J_hana00DL, 0x140);
                    } else {
                        GXCallDisplayList(&l_J_hana00_cDL, 0xC0);
                    }
                }
            }
        }
        sp5C++;
    }

    GXSetArray(GX_VA_POS, mp_pos, sizeof(cXyz));
    GXSetArray(GX_VA_NRM, &l_flowerNormal2, sizeof(cXyz));
    GXSetArray(GX_VA_CLR0, mp_colors, sizeof(GXColor));
    GXSetArray(GX_VA_TEX0, mp_texCoords, sizeof(f32[2]));

    sp5C = m_room;

    for (int i = 0; i < 64; i++) {
        GXColor sp3C = {0xFF, 0xFF, 0xFF, 0xFF};
        dFlower_data_c* sp38 = sp5C->getData();
        if (sp38 != NULL) {
            dFlower_data_c* sp34 = sp5C->getData();
            int sp30 = 0;
            int sp2C = 6;
            dKy_tevstr_c* temp_r29 = dComIfGp_roomControl_getTevStr(i);
            GXColorS10 sp78 = {0, 0, 0, 0};

            if (dComIfGp_roomControl_getStatusRoomDt(i) != NULL) {
                sp2C = dComIfGp_roomControl_getStatusRoomDt(i)->getLightVecInfoNum();
            }

#if DEBUG
            if (g_kankyoHIO.light.m_HOSTIO_setting != 0) {
                sp2C = g_kankyoHIO.dungeonLight.usedLights;
            }
#endif

            if (dKy_SunMoon_Light_Check() == TRUE && sp2C < 2) {
                sp2C = 2;
            }

            if (sp2C <= 2) {
                GXCallDisplayList(mp_mat2Light4DL, m_mat2Light4DL_size);
            } else {
                GXCallDisplayList(mp_mat2DL, m_mat2DL_size);
            }

            GXSetTevColorS10(GX_TEVREG0, sp78);
            dKy_Global_amb_set(temp_r29);
            dKy_GxFog_tevstr_set(temp_r29);
            dKy_setLight_nowroom_grass(temp_r29->room_no, 1.0f);

            f32 var_f29;
            f32 var_f28;
            f32 var_f27;

            f32 temp1 = 0.03125f;
            while (sp34 != NULL) {
                f32 var_f29 = temp_r29->AmbCol.r * temp1;
                if (var_f29 > 1.0f) {
                    var_f29 = 1.0f;
                }

                f32 var_f28 = temp_r29->AmbCol.g * temp1;
                if (var_f28 > 1.0f) {
                    var_f28 = 1.0f;
                }

                f32 var_f27 = temp_r29->AmbCol.b * temp1;
                if (var_f27 > 1.0f) {
                    var_f27 = 1.0f;
                }

                GXColor sp28;

                //u8 sp26, sp25, sp24;
                GXColor sp24;
                sp24.r = -0.4f * temp_r29->AmbCol.r * var_f29;
                sp24.g = -0.4f * temp_r29->AmbCol.g * var_f28;
                sp24.b = -0.4f * temp_r29->AmbCol.b * var_f27;

                u8 sp8 = sp30 & 7;
                switch (sp8) {
                case 0:
                    sp28.r = temp_r29->AmbCol.r + sp24.r;
                    sp28.g = temp_r29->AmbCol.g;
                    sp28.b = temp_r29->AmbCol.b;
                    break;
                case 1:
                    sp28.r = temp_r29->AmbCol.r;
                    sp28.g = temp_r29->AmbCol.g + sp24.g;
                    sp28.b = temp_r29->AmbCol.b;
                    break;
                case 2:
                    sp28.r = temp_r29->AmbCol.r;
                    sp28.g = temp_r29->AmbCol.g;
                    sp28.b = temp_r29->AmbCol.b + sp24.b;
                    break;
                case 3:
                    sp28.r = temp_r29->AmbCol.r + sp24.r;
                    sp28.g = temp_r29->AmbCol.g + sp24.g;
                    sp28.b = temp_r29->AmbCol.b;
                    break;
                case 4:
                    sp28.r = temp_r29->AmbCol.r;
                    sp28.g = temp_r29->AmbCol.g + sp24.g;
                    sp28.b = temp_r29->AmbCol.b + sp24.b;
                    break;
                case 5:
                    sp28.r = temp_r29->AmbCol.r + sp24.r;
                    sp28.g = temp_r29->AmbCol.g;
                    sp28.b = temp_r29->AmbCol.b + sp24.b;
                    break;
                case 6:
                    sp28.r = temp_r29->AmbCol.r + sp24.r;
                    sp28.g = temp_r29->AmbCol.g + sp24.g;
                    sp28.b = temp_r29->AmbCol.b + sp24.b;
                    break;
                case 7:
                    break;
                }

                if (daPy_py_c::checkNowWolfPowerUp()) {
                    f32 var_f30 = g_env_light.bg_amb_col[0].r / 255.0f;
                    sp28.r = (sp28.r + 8) * (6.0f * var_f30);

                    var_f30 = g_env_light.bg_amb_col[0].g / 255.0f;
                    sp28.g = (sp28.g + 8) * (6.0f * var_f30);

                    var_f30 = g_env_light.bg_amb_col[0].b / 255.0f;
                    sp28.b = (sp28.b + 8) * (6.0f * var_f30);
                }

                GXSetChanAmbColor(GX_COLOR0A0, sp28);

                sp30++;

                if (!cLib_checkBit<u8>(sp34->m_state, 4) && cLib_checkBit<u8>(sp34->m_state, 0x40)) {
                    GXLoadPosMtxImm(sp34->m_modelMtx, 0);
                    GXLoadNrmMtxImm(j3dSys.getViewMtx(), 0);

                    if (!cLib_checkBit<u8>(sp34->m_state, 8)) {
                        if (!cLib_checkBit<u8>(sp34->m_state, 0x10)) {
                            GXCallDisplayList(mp_Jhana01DL, m_Jhana01DL_size);
                        } else {
                            GXCallDisplayList(&l_J_hana01_c_00DL, 0xC0);
                        }
                    } else {
                        GXCallDisplayList(mp_Jhana01_cDL, m_Jhana01_cDL_size);
                    }
                }

                sp34 = sp34->mp_next;
            }
        }
        sp5C++;
    }

    J3DShape::resetVcdVatCache();
}

void dFlower_packet_c::calc() {
    dFlower_anm_c* anm_p = getAnm();

    for (int i = 0; i < 8; i++) {
        anm_p->m_angX = 1000.0f + (100.0f * cM_scos(1000.0f * (g_Counter.mTimer + (i * 250))));
        anm_p++;
    }

    int room_no = dComIfGp_roomControl_getStayNo();
    dFlower_data_c* data_p = m_room[room_no].getData();

    if (data_p != NULL) {
        daPy_py_c* temp_r26 = (daPy_py_c*)dComIfGp_getPlayer(0);
        cXyz sp38;
        cXyz sp2C;

        setPlayerCutFlg(temp_r26->getCutAtFlg());

        sp38 = temp_r26->getSwordTopPos();
        sp2C = sp38 - temp_r26->current.pos;

        setPlayerSwordAngY(cM_atan2s(sp2C.x, sp2C.z));

        sp2C = getPlayerSwordTop() - sp38;
        setPlayerSwordMoveAngY(cM_atan2s(sp2C.x, sp2C.z));
        setPlayerSwordTop(sp38);

        data_805284E8 = 0;

        if (!cLib_checkBit<u8>(data_p->m_state, 0x40)) {
            dComIfG_Ccsp()->SetMassAttr(30.0f, 50.0f, 11, 2);
        } else {
            dComIfG_Ccsp()->SetMassAttr(30.0f, 160.0f, 11, 2);
        }

        do {
            if (!cLib_checkBit<u8>(data_p->m_state, 4)) {
                data_p->hitCheck(temp_r26, room_no);
            }
            data_p = data_p->mp_next;
        } while (data_p != NULL);
    }
}

static f32 flowerCheckGroundY(cXyz& param_0) {
    dBgS_GndChk sp8;
    param_0.y += 50.0f;

    sp8.SetPos(&param_0);

    f32 temp_f31 = dComIfG_Bgsp().GroundCross(&sp8);
    param_0.y -= 50.0f;

    if (temp_f31 <= -G_CM3D_F_INF) {
        return param_0.y;
    } else {
        return temp_f31;
    }
}

void dFlower_packet_c::update() {
    dFlower_anm_c* var_r29 = getAnm();

    for (int i = 0; i < 72; i++) {
        mDoMtx_stack_c::YrotS(var_r29->m_angY);
        mDoMtx_stack_c::XrotM(var_r29->m_angX);
        mDoMtx_stack_c::YrotM(-var_r29->m_angY);
        cMtx_copy(mDoMtx_stack_c::get(), var_r29->m_animMtx);
        var_r29++;
    }

    dFlower_data_c* data_p = getData();
    var_r29 = getAnm();

    cXyz sp28;
    int sp14 = 0;

    for (int i = 0; i < 1000; i++) {
        if (cLib_checkBit<u8>(data_p->m_state, 2)) {
            cLib_calcTimer<u8>(&data_p->field_0x03);

            if (cLib_checkBit<u8>(data_p->m_state, 0x20) && sp14 < 8) {
                data_p->m_pos.y = flowerCheckGroundY(data_p->m_pos);
                cLib_offBit<u8>(data_p->m_state, 0x20);
                sp14++;
            }

            sp28.set(data_p->m_pos.x, 260.0f + data_p->m_pos.y, data_p->m_pos.z);

            if (mDoLib_clipper::clip(j3dSys.getViewMtx(), sp28, 260.0f)) {
                cLib_onBit<u8>(data_p->m_state, 4);
                data_p->deleteAnm();
            } else {
                cLib_offBit<u8>(data_p->m_state, 4);

                MtxPtr temp_r28 = var_r29[data_p->field_0x01].m_animMtx;
                temp_r28[0][3] = data_p->m_pos.x;
                temp_r28[1][3] = data_p->m_pos.y;
                temp_r28[2][3] = data_p->m_pos.z;

                f32 temp_f31 = 0.69999999f + (0.3f * ((((s16)data_p->m_pos.x * 3535) & 0xFFF) / 4096.0f));
                
                mDoMtx_stack_c::copy(temp_r28);
                mDoMtx_stack_c::scaleM(temp_f31, temp_f31, temp_f31);
                cMtx_concat(j3dSys.getViewMtx(), temp_r28, data_p->m_modelMtx);
            }
        }

        data_p++;
    }

    dComIfGd_getListPacket()->entryImm(this, 0);
}

void dFlower_packet_c::setData(dFlower_data_c* i_data, int i_dataNo, s8 param_2, cXyz& i_pos,
                               int i_roomNo, s8 i_tableNo, s16 i_addCol) {
    f32 y_pos;
    if (fopOvlpM_IsPeek()) {
        y_pos = flowerCheckGroundY(i_pos);
        i_data->m_state = 6;
    } else {
        y_pos = i_pos.y;
        i_data->m_state = 38;
    }

    if (param_2 == 2) {
        cLib_onBit<u8>(i_data->m_state, 0x40);
    }

    i_data->field_0x01 = cM_rndF(7.0f);
    i_data->m_pos.set(i_pos.x, y_pos, i_pos.z);
    i_data->m_tableNo = i_tableNo;
    i_data->field_0x03 = 0;
    i_data->field_0x04 = i_addCol;

    if (m_room[i_roomNo].mp_data == NULL) {
        mp_pos = l_flowerPos2;
        mp_colors = l_flowerColor2;
        mp_texCoords = &l_flowerTexCoord2[0][0];
        mp_mat2DL = l_mat2DL;
        m_mat2DL_size = 0x80;
        mp_mat2Light4DL = l_mat2Light4DL;
        m_mat2Light4DL_size = 0x80;
        mp_Jhana01DL = l_J_hana01DL;
        m_Jhana01DL_size = 0x120;
        mp_Jhana01_cDL = l_J_hana01_c_01DL;
        m_Jhana01_cDL_size = 0x120;
    }

    m_room[i_roomNo].newData(i_data);
    m_dataNum = i_dataNo;
}

dFlower_data_c* dFlower_packet_c::newData(s8 param_0, cXyz& i_pos, int i_roomNo, s8 i_tableNo,
                                          s16 i_addCol) {
    dFlower_data_c* data_p = m_data + m_dataNum;

    for (int i = m_dataNum; i < 1000; i++) {
        if (!cLib_checkBit<u8>(data_p->m_state, 2)) {
            setData(data_p, i, param_0, i_pos, i_roomNo, i_tableNo, i_addCol);
            return data_p;
        }
        data_p++;
    }

    data_p = m_data;
    for (int i = 0; i < m_dataNum; i++) {
        if (!cLib_checkBit<u8>(data_p->m_state, 2)) {
            setData(data_p, i, param_0, i_pos, i_roomNo, i_tableNo, i_addCol);
            return data_p;
        }
        data_p++;
    }

    return NULL;
}

void dFlower_packet_c::deleteRoom(int i_roomNo) {
    m_room[i_roomNo].deleteData();
}

int dFlower_packet_c::newAnm() {
    dFlower_anm_c* anm_p = m_anm + 8;
    for (int i = 8; i < 72; i++) {
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

void dFlower_packet_c::setAnm(int i_idx, s16 i_angY) {
    dFlower_anm_c* anm_p = m_anm + i_idx;

    anm_p->m_state = 1;
    anm_p->m_angY = i_angY;
    anm_p->m_angX = 0;
}

dFlower_room_c::dFlower_room_c() {
    mp_data = NULL;
}

dFlower_anm_c::dFlower_anm_c() {
    m_state = 0;
}

dFlower_data_c::~dFlower_data_c() {}

dFlower_data_c::dFlower_data_c() {
    m_state = 0;
}
