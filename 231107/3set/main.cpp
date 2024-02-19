#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init();
extern char putString(char mStr[]);
extern char getWord(int mX);

//////////////////////////////////////////////////////////

#define INIT	0
#define PUT		1
#define GET		2

static bool run()
{
	int cmd, mx;
	char ansc[5], retc;
	char str[21];

	int Q = 0;
	bool okay = false;

	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case INIT:
			init();
			okay = true;
			break;

		case PUT:
			scanf("%s", str);
			retc = putString(str);
			scanf("%s", ansc);
			if (ansc[0] != retc) {
				okay = false;
			}
			break;

		case GET:
			scanf("%d", &mx);
			retc = getWord(mx);
			scanf("%s", ansc);
			if (retc != ansc[0]) {
				okay = false;
			}
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}