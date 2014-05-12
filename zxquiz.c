
#include<stdio.h>

#define BR_PIT 10
#define BR_ODG 4

char *pitanja[BR_PIT]={
	"Koje godine se 'ZX Spectrum' pojavio na trzistu?",
	"Koji procesor se nalazi u 'ZX Spectrum'-u?",
	"Odakle ZX imenu 'Speccy'-ja?",
	"Koliko memorijskih cipova ima 'ZX Spectrum 48K?'",
	"Kako se zove autor 'Sinclair BASIC'-a?",
	"Koja je velicina ROM-a koji se nalazi u 'ZX Spectrum 48K'?",
	"Na kojoj adresi pocinje printer bafer u RAM-u 'ZX Spectrum-a'?",
	"Koja je graficka rezolucija 'ZX Spectrum'-a?",
	"Kako se zvala kompanija koja je proizvela 'ZX Spectrum 48k'?",
	"Koliki je raspon tonova zvucnog izlaza 'ZX Spectrum 48k?'"
};

char *odgovor[BR_PIT*BR_ODG]={
	"1980", "1981", "1982", "1983",
	"MOS6502", "Z80", "MC6800", "i8080",
	"Zbog misterije", "To su inicijali tvorca", "Jer su u donjem levom uglu tastature", "Slucajno",
	"1", "8", "16", "32",
	"Klajv Sinkler", "Ricard Altvaser", "Stiv Vikers", "Marko Kraljevic",
	"4kB", "8kB", "16kB", "32kB",
	"16384", "23296", "32768", "65500",
	"32x24", "256x192",  "320x200", "640x480",
	"Sinclair Research Ltd.", "ZX Spectrum Inc.", "Commodore Intl.", "Amstrad Plc.",
	"4 oktave", "6 oktava", "8 oktava", "10 oktava"
};

char tacno[BR_PIT]={
3,
2,
1,
3,
3,
3,
2,
2,
1,
4
};

int pit_br;
int odg_br;
int br_poena=0;
int tipka;


main(){
	printf("%c%c%c**********  ZX  KVIZ  **********\n\n",12,1,32);
	printf("%c%cDobrodosli u kviz o poznavanju jednog o najpopularnijih 8-bitnih racunara 80-tih godina u bivsoj SFRJ, 'ZX Spectrum'-a. ",1,64);
	printf("Kroz %d pitanja bice provereno Vase znanje o pojedinostima o njegovom nastanku i funkcionisanju.", BR_PIT);
	printf("\nZa pocetak kviza pritisnite bilo koju tipku. Srecno!");
	getchar();

	while(1){
	for(pit_br=0;pit_br<BR_PIT;pit_br++){
		printf("%cPitanje %d. od %d:\n %s\n", 12, pit_br+1, BR_PIT, pitanja[pit_br]);
		for(odg_br=0;odg_br<BR_ODG;odg_br++){
			printf("\t[%d] %s\n", odg_br+1, odgovor[pit_br*BR_ODG+odg_br]);
		}
		printf("\nTipke 1-4 za izbor odgovora\nTipka BREAK za izlazak\n");

		while(1){
			tipka=getchar();
			if(tipka>'0' && tipka<=(BR_ODG+'0')) break;
			if(tipka==' ') goto kraj;
		}
		printf("Vas odgovor je %c\n\n", tipka);
		if((tipka-'0')==tacno[pit_br]){
			br_poena++;
			printf("TACNO!!!\n\n");
		} else printf ("Pogresno.\n\n");
		if(pit_br!=BR_PIT-1){
			printf("Za nastavak pritisnite bilo koju tipku");
			getchar();
		}

		
	};
kraj:
	printf("Broj osvojenih poena je %d od mogucih %d\n", br_poena, BR_PIT);
	printf("Da li zelite da pokusate jos jednom? (D/N)\n");
	tipka=getchar();
	if(tipka!='d' && tipka!='D') break;
	}
	printf("Hvala na ucescu u kvizu!\n\n");
}
