// Hubert Jastrzębski | Diamentowy Indeks AGH XVII 1 (Liczba e) | 2023-10-21
// https://www.diament.agh.edu.pl/wp-content/uploads/2024/01/Etap_I_zadania_Informatyka.pdf

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const string NUM = "=4>4>O~!O9W_>mjE<aSp[:i~%h~+^[Se~(o=kJob%WXn~&[/u3x;2c=LmeI5B!@^~$43KE~(a~!M[?!CL~'<'~'b)H/9>arMS)b9H?{)W5VU#~!-[HD4r@i7X*~#S~%Rw2n+:Q`P(g*8cs#gQm-xGLDXLMj)W~!pmS~$(~'Ui=`vy(</AHOv!)V&SCud_?o(lj/6)+Bz+.mMmiQ9(~(~)k+A#Kh>Ft~!;UU*dmbp7-;9|qN;'hWhfiqXS~(~+f~&gcOS'~*rAbg|9!~*rA=l`q7X:~+~$?[bUR8*<~*~'5Fg%AuV{hIw~(PU'u+I9~*?Rz~%B%aT~&M-l#9t~)(w20%~)#~*Gf~%6gBuGccsL~'A4$BzuT~*5O]1@3Zjl`C6ht.T~+`t{1~%&2~!E1~*{x5D])=Helx|L>r8w~+|6ys];m~$r`&w5wNFDb:SgRn_9F:uiK~)y96~!$2+~!9W&F~+Kw~#PAJ~%M3H0FJXaW16~(4F~!{z)#fgIc:GtJ^=0ZES(/%,k*U%vn',-[QiKj|y,gl~(~(Y7<jXg|[%TEJ79JqSt~%DB,g3#7!Z={$E5@C8QO#]W~!Q@K~+[pi~%TF_Kh~)B~);*yzheJEYija<wQ2;_r{<UqjD5U:eV#%'~$.Ffj~&BVqfW~*Y|N|hi~(J~)X^4Z~'bs9bi27.&pLk>FR~(/L;2NTq4:LE?Rbbk03J9{~%N.Q~(EmG$bnV~&NvG~+s2.X~$=x+;puZ6~$a<RBap~%CyZctap;2J5,^!S2N~+u|ATZ_Q;s=qb4c1U~'dBN;y~*?P~'~%*#~#V~*k-kYbQXb~(Nr,0^&+'y?w~(r.zJgiTR~'xyjmrxPfnnl6Zt>w^6X/D'I8!#/qb!~&Y_gtem!2~*L']&%FG~'GcV%&$M8Z`E=vhU3qvyHmM~(aW8Sx(X~+]y9Lt|~))lBo33v~$sD~&d#MO]|ij~&;yIzknQ,~(?Wm17-UFvTan<$Bcwkz%~$)cA!^]K2`6XV~)%$FQ;S?ehH-UGB=WcT~*{~!AF$'kR3dx-sb%cLt90~(Y)&n,;Nd#3=71Y5Rex*!FxB>4AV5_%lZ;=~&SU]>K{?Qz`*Vb~*/~'^~!(loR?8NGVz4P:[sF5?t~)/~+0ncRua_I%H0KuBaUT~)R=~*pr~(Ml*~+iH{fq8jHF'p?quK;`5)3eIPTib@O=~'P`xT~(e`xeQ+j/NQJ2)&aa1g)3R4pwMjMh{7x^f+^,;~(y6$EG4]zRZ~(V6!TA3DI6l7/~!sB~%bNrklY~'VpD~!jqG~%L2G#6T'O/<HEN!#yBI~#S)'Q~)q'e~)xC]&|e~!a~'-~&BQ@~+]oY9g.x~!KHBK2)8_?~*C'EG*o/|Ib~#p~'mX#`G8F4q~%d<'H1]K]jy~$YH_`cp~*D$XE.wI`?P%V~#C;~&=~&~!MG?~!xl1s?+]b/ugB~#Qj2IbG+:!Ag~&]b__c]O~$U<~+PYkRI4dc6~)VgTu@nN;O~+Gh3&5pq!xF=@~&3,2DD~!o~(LG8?MVF`;[;*tQr8AU~)Qq('hf;H#jspb_DaO~$qpwdx(Z')swL-V~(~)V4~!zJ5e+(d4%Ud#r;&`~'#FdxMeBj;Sb~+*X~#N6!0[Q_t~%$76e$M@+c.iR~&I%~)3j~'4(~+*h~*_eF]BB=z+Gd$<#S?,-Ujpb^N_69:~%!>&#yp9~#${+qe_ZU4B_&F{T{31kHe~*L:8#$STY4thR%8,$UX<SPIt>lfo]~$o{2E~*A:p{d60-m-+/_-c~+Toa~!p~&FP!]U~&5~*Z#acr)`W7%z=Yj<~+;4=Zz~*~%$o3`0`aX~%ZS^%rsOvtuBCg`62:GFZ~*PiGxxC'=]CCrI~!n7e(~$H'Ch{rZUG>Y~%{D~+|Q)K`tY#;Iicctj~&f*Dt~)7N{|z~!fd%r^%e~(kSS~$XVr%G?b`ad|o%~&~*[fKIl^N,9mM?i~%YQrua~(0^0L~%cULy31xzC~)Pr4~)[.-~'`zH[vcQ]Nw9YYt'!;`0~$I14|@~+PD>KIF*%v+2at{-TG1>Sf'~)KaZ>9_~$2sn1#pkWzJ;c;Diz~!|/k~#k>>`11~#ZvkVKb)k;N(Cqn~%,^uf_~&L%<5:>W3#ztp?_9X/((k/_P!%|e,~%ci~'0034[p#Ks_cMbg1PNJ'C2*pv0AmN*-~&~&8~)Y~+AJ-{yvARBs=(YHC!P~%?#1mKQZAI~+k7iH&`i~$|Or+aje8_m)4m~+nE~$.n_wKQGuC%=%@2uG5FR!7l>[D~%^QZMD.~+M$RT9[B7O~)wBuc07gRqk2lFi,`T~&:DZ~*N#zC.t#)~&U=8GG{`<'tdesWjM~(.q{l;=GH~!I>~!TgdBKH(=~($^@Hp=hpvr>gJ~%;F]slI{Ok4m_7!W-RCUBHT&q=2~%o7s&~!Q~'^r^?'~#dXiT[pUM*3U.h|x4w*jxc$_E@YvlqBL?:4Z;cLY$<k1^s=J.`rj~$sQ/~(!g~#buyd=i+n=f(~)p%cI<$:G>Kw*v;4Rp&kbwJG~'@2h'P^GP25BHJFH~%//cBjGg{K$g-7~*~#=V9'aZnaXi3;*bSoWf>y'~(fVm*gam)~#>Z[h~(AG|n@De(2e~*&7ufkO_W(_pH~+aL4D*^{6jyPuaB1*${>b^mgIdM]xexTGl/.~(]rnt'#7S26oZo~+Td~)1DQbQ%6xB1_Fmuy*GyZs@l(<[bDhpL~'bPMjf+Ij~%(*o~(D~'B{PvF/%{?M,Js$~(zHh-iee`Ps!1.-MN8Z$HmQM;;)hHippU~%?~+L/kp7.]wF*j]DvZ<~(2`~*'kVe.6f~)X(7(6sc~*u~#wXIW#V~+u+;%!X~*;iMI'W[#gdA6Vc~'`R[:~$[Ha(~#m%hV/WGBW2eDXe]x~)>e^O-FN/iC/~%f74Z~'W~'7*Ow):M9vYy(A(shc~$RU9<Bh~'0_E~(%k~);A~*Fw9FI&b7Fj#25>7j-T>>#_N{'{$H6A~*0~%+bh^fEv=L$S{:Zw~&.ly'eS/VVf(&aDO'S8nt13+AS7z~'~$js#~&+gyhyviG@8!QW0Ctt+=*%!36^EW'6i)()8C~+~&b~+'jA1z+~(Epl^$j~(>T`0d0vn<6~'dDf/?!;~+M~)eA0X^$g]~*~)~#1vi~%K~%iN-Y.56-jc{'e~&^H/-vwGda(=wb,S%P?IT$~&]D-cuK0~(~)]B_-s)Ah~&GIE(~(a~'j:,=BI/zKnS9)4aOOM86IY=E?VJ:^%s[NT>~$:gy>WFX8/t[8/-b>t.'7PR~*'4!~$$Q5I3,YW~!-IMAetU]>wFz_h`,;'3,)I=aHYWHakYEHv+_f2Ne9i~$<Ps~(j;J`y~'$0Ao72g0!~)^VtSI)8<#-<t1A*Hl3`l99Vb_]H3AU%O~'ldH8ED~+?Eu>Fx,)t*wbMS~*E4JNUiLi4~%t~+LMK!~![Wo;pf[-4+!{2KvA~$#~(<9Ka{2d7GQ3BXpkpvRzmFd4uzV1exj~'(G5FZW~!H~&SFc7oJ%.1=z$8Fcbb[YTEd[hR{dST$ixI9`j'T7A0m/mK(/NOXK~$,/F3?~(>Z~&|~#~%F~#wk~&q])?1_{U%~(q5^L~*C4csn_vf~'USeFN|d^?R4qUqJHpC<:iU~&TTK~*Qm604IQl.$t]yw[)?'N'n,_.x;sZ^Q%&gFDO~$d;V/i*(zV!~'~%OF)Aa<-z>3I>)P9+PxFq9,_~)~$1~+F!5~&aG~+DD7(ztD~)Dh^:chn;(:h]`h+3xl~)d~'5~%~$~+I~'ZnLjPX~#&Zy)$+~!._g4iSw3sr3I:)5O~+b9($Xir#pO=UAys~+u>Q@y)eWgexY2Pp$~#/Funb,k9Df<-G'S)~'F]DWyG5aExb.`vz1fm-zHVp8~$;~&mClqZ~'WwZ:g##I'kqj#d.~(eFoNUz:ddG@J:MgKJtN{l?[wlRS!%#~&p{s6P%:e*LzWUwvc~'~#~'*>{BB(V7>,K~!NsQ:rS?/L>SU~)!8_/,M!aK)3~)1$rDC<D)~+^_W0P'B@Rx>~)?3d~*o#eft5G~%9kOH[6~()]8p3wvF2/]<.|a<-t?O^=P=f/p~&RnynF[XR`Jo-~%-;~'x.d[^lOl#WCc<@orxNCxo31CDaBVi[6'@I{>~&~+%L^ZaB~)[uRzE$~$^2g;|NZ|PY~+<]OQahO>q'2T36fQxKqz~*8osdFd(K~#+lMO>zvHa3<1ah]<XQu'f?znc<BW7^L~&KsI~&B3!!~!X<To@~']wd|Uji~#Q_mG/g~%A~&h++t~!O#?%)+~'e8e6@Auc~%dlF~*K~'Yphbqo:~#{VyZy_o!Z_;_XOj/G>gJ6YmK_@viVA8L]k9M{X.ArR/{Y!ng~%t.SEHb4bVz*G~+wZ~$`~+trO9FJzL~'~#4)QOD5Y06E3<4L!wY+3*Og9g6*~)l~&Yw<r7LlQn_z~(N=~$$iv.1#ZJbKD232cR(~*1RGcS1l~!#77iKXqk^5~*~&H;FSTUQjG~%~+0k'7~'?)~%~(/o7,kHSL~!`b[_O~(9.WT_gWoULA1D~(dgG1-e&8)~(INea-b;U[k~!i~)wl1aq=n~*qtFS5U;mvBz~%p1jO~!~#(RKc<q@~+SkFmL#ny8hJ7^Jr:R'K;W_M/3~+<~(l~#[X:5?e)A9~%oEL/~$@`qonI]j0F,J|J~+e*~&jKvJhva~+FnF<7XVQ?wc7GV|,r{Mt@_~'Y<8k*GUy?vieqk:M#~'rG~%q_k,kX=k|)3BxRmGMYq5eU32`v@{-?.$O6JRg8!)9N%T;Nu$vLX4qwdF$^1(NVjdp!&O7+pE]]~)a<YRSKa30~*~'BHD7_#0(?Tjw~!Lp|;xVm@E8/~(vZr#soJ_L/v)@zmP#iw<{=8`3jsw<cCFUq!$35%N~$D<Le?8`O_&ClvyvEYWMO@&<R4QI|7Z=*_~'d(?D&'<SM:L`NZd~$.~#8ZR|EhdT+1M(L`D;<gQ;~&~#M09~%~*wXBRb=P4LweY~*WBA8,Pa^|#Kj7%N_w=22`~!#;j~'z)~%7nhhxN#C~)a6~(m~&X4X)-wPMIP~+#ahvU_qR~$O0'|J~&b~'<q)EOri%)'-bg;5Rp#4~)c!>=cw02'z6`w4V~)4~#X#~({;B|@~#SeWOnEjLl4R62HPNv:~+%qy(~!*)=+Bol.nt~(db~&-R~(32v?sOUIk~'(go&m+1L&>L~+~%X,;u~#/T8Kh)hM2g[LLV;+$hI%R0xcU@@h~$U~+^&FHJ>L~$fK;lL:QoYw3qy33G<Xa*X~*?N~*~&fzE+?]2Vb6k;|~$FzgOi3u@H+df{A.>~%'s~#J[<,y]ww]l,2]1-fWC=fRz#R?2m5i1.Y~)u[=)JcAsy#LtS$KPq&kBn~)gLhbIEpEL~%#yl~&Ijb{`3c6~!&(ybI{Zw2t!HkH~$0RAo)#2gO%{k.FMf&C0+-YlBs4?p~*zF^+2d~(.J67px]xRo3``~*~%irMs'ebFRwFT|0R'[,IoV0h_=e;v^~!U~*iL@#rPYFqxf";
const string CHARS = "!#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~";

int main()
{
    int n;
    cin >> n;

    map<char, int> CTOI;
    for (int i = 0; i < CHARS.size(); i++)
        CTOI[CHARS[i]] = i;

    vector<int> V;
    for (int i = 0; i < NUM.size(); i++) {
        int num = CTOI[NUM[i]];
        if (num == CHARS.size() - 1) {
            V.push_back(9);
            V.push_back(CTOI[NUM[++i]]);
        }
        else {
            V.push_back(num / 10);
            V.push_back(num % 10);
        }
    }

    int res = 0;
    for (int i = 0; i <= n; i++)
        res += V[i];
    cout << res;
}