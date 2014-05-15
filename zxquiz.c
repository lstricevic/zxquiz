
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BR_PIT 20  // Ukupan broj pitanja u bazi
#define BR_ODG 4   // Broj odgovora po pitanju
#define BR_KVPIT 10 // Broj pitanja u kvizu
#define VREME_PIT 60  //Vreme po pitanju (sek.)

char *pitanja[BR_PIT]={
	"Koje godine se 'ZX Spectrum' pojavio na trzistu?",
	"Koji procesor se nalazi u 'ZX Spectrum'-u?",
	"Odakle 'ZX' imenu 'Spectrum'-a?",
	"Koliko memorijskih cipova ima 'ZX Spectrum 48K'?",
	"Kako se zove autor 'Sinclair BASIC'-a?",
	"Koja je velicina ROM-a koji se nalazi u 'ZX Spectrum 48K'?",
	"Na kojoj adresi pocinje printer bafer u RAM-u 'ZX Spectrum-a'?",
	"Koja je graficka rezolucija 'ZX Spectrum'-a?",
	"Kako se zvala kompanija koja je proizvela 'ZX Spectrum 48k'?",
	"Kako se zvala kompanija koja je proizvela 'ZX Spectrum +2'?",
	"Koliki je raspon tonova zvucnog izlaza 'ZX Spectrum 48k'?",
	"Ko je autor popularne igre 'Manic Miner'?",
	"Kako se zvao poslednji racunar sa oznakom 'ZX Spectrum'?",
	"Prema kom knjizevnom delu je nastala jedna od prvih grafickih avantura za 'ZX Spectrum'?",
	"Koji cip generise sliku na 'ZX Spectrum'-u?",
	"Standardna brzina ucitavanja programa sa kasete na 'ZX Spectrum'-u je:",
	"Prednost 'ZX Spectrum'-a u odnosu na 'Commodore 64' je:",
	"'Jet Set Willy' je po zanimanju:",
	"Kako glasi naslov kasete koja se dobijala uz 'ZX Spectrum 48k'",
	"Kolika je velicina video memorije na ZX Spectrum-u 48k?"
	
};

char *odgovor[BR_PIT*BR_ODG]={
	"1980", "1981", "1982", "1983",
	"MOS6502", "Z80", "MC6800", "i8080",
	"Zbog misterije", "To su inicijali tvorca", "Jer su u donjem levom uglu tastature", "Slucajno",
	"1", "8", "16", "32",
	"Klajv Sinkler", "Ricard Altvaser", "Stiv Vikers", "Rik Dikinson",
	"4kB", "8kB", "16kB", "32kB",
	"16384", "23296", "32768", "65500",
	"32x24", "256x192",  "320x200", "640x480",
	"Sinclair Research Ltd.", "ZX Spectrum Inc.", "Commodore Intl.", "Amstrad Plc.",
	"Sinclair Research Ltd.", "ZX Spectrum Inc.", "Commodore Intl.", "Amstrad Plc.",
	"4 oktave", "6 oktava", "8 oktava", "10 oktava",
	"Metju Smit", "Filip Micel", "Kosta Panaji", "Kevin Toms",
	"ZX Spectrum +", "ZX Spectrum +2", "ZX Spectrum +3", "ZX Spectrum +4",
	"Hobit", "Gospodar prstenova", "Letopisi Narnije", "Hari Poter",
	"Z80", "4116", "ULA", "VIC",
	"u proseku 300bps", "u proseku 1500bps", "uvek 2500", "uvek 3000bps",
	"brzi procesor i bolji BASIC", "bolja tastatura", "bolji zvuk", "vise RAM-a",
	"programer", "djubretar", "spijun", "rudar",
	"Sunrise", "Video Driver", "Audio Manual", "Horizons",
	"6kB", "7kB", "8kB", "9kB"
	

	
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
4,
4,
1,
3,
1,
3,
2,
1,
4,
4,
2
};

char ipit[BR_PIT];

int pit_br;
int odg_br;
int tipka;


// Funkcija vraca sadrzaj FRAMES
// (sluzi kao slucajan broj)
int my_rand(void){
	#asm
	ld a, (23672)
	ld l, a
	#endasm
}

// Inicijalizacija sl. niza indeksa (Fisher–Yates shuffle)
ipit_init(void){
	int i,j;
	for(i=0;i<BR_PIT;i++){
		j=rand()%(i+1);
		if(i!=j) ipit[i]=ipit[j]
		ipit[j]=i;
	}
	
}

// Ocitava tastaturu (LAST_K) tokom zadatog vremena
int get_timedkey(void)
{
	int key;
	long end_time = clock()+(VREME_PIT*50);
	#asm  //obrisi LAST_K pre citanja
	xor a
	ld (23560),a
	#endasm
	while(1){
		if(end_time<= clock()) break;
		key=getk();
		if(key>'0' && key<=(BR_ODG+'0')) break;
		if(key==' ') break;
	}
	return key;
}

main(){
	int i;
	int br_poena;
	int proc_poena;

	printf("%c%c%c**********  ZX  KVIZ  **********\n\n",12,1,32);
	printf("%c%cDobrodosli u kviz o poznavanju jednog o najpopularnijih 8-bitnihracunara 80-tih godina, 'ZX Spectrum'-a. ",1,64);
	printf("Kroz %d pitanja bice\nprovereno Vase znanje o pojedinostima o njegovom nastanku i\nfunkcionisanju. ", BR_KVPIT);
	printf("Za svako pitanje je ponudjeno %d odgovora, koje\nbirate pritiskom na tastere '1'-'%d'. ", BR_ODG, BR_ODG);
	printf("Vreme za odgovor na svako\npojedinacno pitanje je %d sekundi. ", VREME_PIT);
	printf("\n\nZa pocetak kviza pritisnite bilo koju tipku. Srecno!");
	printf("%c%c\n\n\n\n\n\n\n\n\n\n\n\n%c \"ONCE UPON A BYTE\" 2014%c%c", 1, 32, 0x7f,1,64);
	getchar();
	srand(my_rand());

	while(1){
	ipit_init();
	br_poena=0;
	for(i=0;i<BR_KVPIT;i++){
		pit_br=ipit[i];
		printf("%cPitanje %d. od %d:\n %s\n\n", 12, i+1, BR_KVPIT, pitanja[pit_br]);
		for(odg_br=0;odg_br<BR_ODG;odg_br++){
			printf(" [%d] %s\n", odg_br+1, odgovor[pit_br*BR_ODG+odg_br]);
		}
		printf("\n\nTipke 1-4 za izbor odgovora\nTipka BREAK za izlazak\n");

		tipka=get_timedkey();
		if(!tipka) continue;
		if(tipka==' ') break;

//Deo koji ispisuje tacnost odgovora i ceka na tipku za nastavak

//		printf("Vas odgovor je %c\n\n", tipka);
		if((tipka-'0')==tacno[pit_br])
//		{
			br_poena++;
//			printf("TACNO!!!\n\n");
//		} else printf ("Pogresno.\n\n");
/*		if(i!=BR_KVPIT-1){
			printf("Za nastavak pritisnite bilo koju tipku");
			getchar();
		}
*/
		
	};
	proc_poena=(100*br_poena)/BR_KVPIT;
	printf("%cProcenat osvojenih poena je %d%%\n\n", 12, proc_poena);
	printf("Da li zelite da pokusate jos jednom? (D/N)\n");
	do{
		tipka=getchar();
	} while (tipka!='d' && tipka!='D' && tipka!='n' && tipka!='N');
	if(tipka=='n' || tipka=='N') break;
	}
	printf("\n\nHvala na ucescu u kvizu!\n");
}
