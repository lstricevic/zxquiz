
zxkviz.tap: zxkvizbas.tap zxq-scr.tap zxq-bin.tap
	cat zxkvizbas.tap zxq-scr.tap zxq-bin.tap > zxkviz.tap
zxq: zxquiz.c
	zcc +zx -lndos -create-app -o zxq zxquiz.c
zxkvizbas.tap: zxkviz.bas
	zmakebas -a10 -n "ZX Kviz" -o zxkvizbas.tap zxkviz.bas
zxq-scr.tap: zx_Kvizscr-inc.asm ZXKviz-oupb256192-4bit.png.scr
	pasmo --tap --name zxq-scr zx_Kvizscr-inc.asm zxq-scr.tap
zxq-bin.tap: zxq-inc.asm zxq
	pasmo --tap --name zxq zxq-inc.asm zxq-bin.tap
