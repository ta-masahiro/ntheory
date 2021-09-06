#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#define TRUE 1
#define  FALSE 0

int fermat(mpz_t n, mpz_t a) {
    mpz_t b2; mpz_init(b2);

    mpz_sqrt(a, n);
    mpz_mul(b2,a,a); mpz_sub(b2,b2,n);
    while (mpz_perfect_square_p(b2) ==0 ) {
        mpz_add_ui(a,a,1);
        mpz_mul(b2,a,a); mpz_sub(b2, b2, n);
    }
    mpz_sqrt(b2,b2);mpz_sub(a,a,b2);
}
//差が15bitの2数の積4096bit整数を分解可能　1034186074668005446865661651578208369514158803552244005581133348807218259696136975186768057532805396894757503164834709575083359161158060701923008831149233177215596305395749862300700772298386522636562203611668211601359078939366452933448401372783149865070405032946502692195960337152490393257718681775969357953766124434670452760182942622011519373645653657784274264774773270847089540432369489508909290697992927057404389218509541644042197448296417276686963995927414541514778710278820030649227976349765070908207584414253880096569270321293357683127769728901749940165024782079154839570419235490028108256539125090626571373643257455521820767805808214404175900736109428513289545954241551995058498737472560704736894014465695117165251699935296644992760434412206519036326801985540077086806228464411438175416317958133959586691011057808141234300883692932436022122663781160823472736298914304029803683697389880156222528045623045436226522780569221934366978973936408257173404970887883159180079205465195884955186605310665826226975454171035075016280417683011623124380312403051425940705920625660567584606796218038626946234225864706878239646554381165540673005572649955471689205027195933802181344480474070023069194083134722979170599617466579222550596280381011
int main(int argc, char * argv[]) {
    mpz_t a; mpz_init(a);
    mpz_t  n; mpz_init_set_str(n, argv[1], 10);
    if (mpz_probab_prime_p (n,20)) 
        printf("%s is prime\n",mpz_get_str(NULL,10,n));
    else  {
        fermat(n,a) ;
        mpz_tdiv_q(n,n,a);
        printf("%s is  %s * %s\n",  argv[1], mpz_get_str(NULL,10,a), mpz_get_str(NULL,10,n));
    } 
}