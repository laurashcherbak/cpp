#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // !#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int Count(char* s)
{
	int k = 0,
		pos = 0;
	char* t;
	while (t = strchr(s + pos, 'S'))
	{
		pos = t - s + 1;
		//cout << t << " : " << pos << " : " << k << " : " << s[pos] << endl;
		if (s[pos - 1] == 'S' && s[pos] == 'Q') {
			//cout << s[pos] << endl;
			k++;
		}
	}
	pos = 0;
	while (t = strchr(s + pos, 'Q'))
	{
		pos = t - s + 1;
		//cout << t << " : " << pos << " : " << k << " : " << s[pos] << endl;
		if (s[pos - 1] == 'Q' && s[pos] == 'S') {
			//cout << s[pos] << endl;
			k++;
		}
	}
	return k;
}

char* Change(char* s)
{
	char* r = s;
	int sLen;
	int sPos;
	char* sBuf = new char[256];
//	char* t = new char[256];// [strlen(s)] ;
	//char* sBuf[256];
	//char c[3];

	//*s = 0;
	//strcat(s, t);

	//c[0] = 'S'; c[1] = 'Q';
	//"aSQbQScSQdQSesqqs." : 17
	//  012345678901234567
	//       SQdQSesqqs. : 11
	//       012345678901
	//s = strstr(s, "SQ");
	//while(s)
	//while (s = strstr(s, "SQ"))
	while ((s = strpbrk(s, "SQ")) != NULL)
	{
		sLen = strlen(s);
		sPos = sLen - strlen(s);
		//cout << s[sPos] << s[sPos + 1] << endl;
		if ((s[sPos] == 'S' && s[sPos + 1] == 'Q') || (s[sPos] == 'Q' && s[sPos + 1] == 'S')) {
			//s = strpbrk(s, "SQ")
			//*t = 0;
			//strcpy(s, t);
			strcpy(sBuf, s + 2);//bQScSQdQSesqqs.
			s[sPos] = '\0';
			//cout << sBuf << endl;
			//cout << s << " : " << strlen(s) << " : " << sPos << " : " << sLen << endl;
			strcat(s, "***");
			strcat(s, sBuf);
			//s = strstr(s, "SQ");
			//cout << strstr(s, "SQ") << endl;
		}
		//cout << s << endl;
	}
	//cout << s << " : " << strlen(s) << " : " << sPos << " : " << sLen << endl;

	//strcat(t, s - 10);
	//strcpy(s, t);

	return r;

	//for (int i = 0; i < strlen(s); i++) {
	//	cout << s[i] << endl;
	//}

	//s = strstr(s, "QS");
	//while (s)
	//{
	//	sLen = strlen(s);
	//	sPos = sLen - strlen(s);
	//	strcpy(sBuf, s + 2);
	//	s[sPos] = '\0';
	//	strcat(s, "***");
	//	strcat(s, sBuf);
	//	s = strstr(s, "QS");
	//}

	//c[0] = 'Q'; c[1] = 'S';
	//s = strstr(s, c);
	//while (s)
	//{
	//	sLen = strlen(s);
	//	sPos = sLen - strlen(s);
	//	strcpy(sBuf, s + strlen(c));
	//	s[sPos] = '\0';
	//	strcat(s, "***");
	//	strcat(s, sBuf);
	//	s = strstr(s, c);
	//}


	//char text[1024];
	//char sBuf[1024];
	//char str1[32];
	//char str2[32];
	//long sLen;
	//long sPos;

	//cout << "Enter input text(less than 1024 chars)\n";
	//cin.getline(text, 1024);
	//cout << "Enter str1 : ";
	//cin.getline(str1, 32);
	//cout << "Enter str2 : ";
	//cin.getline(str2, 32);

	//char* s = strstr(text, str1);
	//while (s)
	//{
	//	sLen = strlen(text);
	//	sPos = sLen - strlen(s);
	//	strcpy(sBuf, s + strlen(str1));
	//	text[sPos] = '\0';
	//	strcat(text, str2);
	//	strcat(text, sBuf);
	//	s = strstr(text, str1);
	//}
	//cout << "String after replacing\n" << text << endl;



/*
	char* t = new char[strlen(s)];
	char* p;
	//int pos1 = 0,
	//	pos2 = 0;
	*t = 0;

	//p = strstr(s, "SQ");
	//cout << s << " : " << p << " : " << p - s << " : " << strlen(s) << " : " << p - s << endl;
	//char replacer[3] = {'*','*','*'};
	while ((p = strstr(s, "SQ")) - s < strlen(s) //&& p - s >= 2
		) {
		cout << s << " : " << p << " : " << p - s << " : " << strlen(s) << " : " << p - s << endl;
		//cout << p << endl;
		//strcat(t, )
		strncpy(p, "**", 2);
		//strncat(t, s + pos1, pos2 - pos1 - 2);
		//strcat(t, "***");
	}
	while ((p = strstr(s, "QS")) - s < strlen(s) //&& p - s >= 2
		) {
		cout << s << " : " << p << " : " << p - s << " : " << strlen(s) << " : " << p - s << endl;
		//cout << p << endl;
		//strcat(t, )
		strncpy(p, "**", 2);
		//strncat(t, s + pos1, pos2 - pos1 - 2);
		//strcat(t, "***");
	}
	//while ((p = strstr(s, "SQ")) - s < strlen(s) && p - s >= 2) {
	//	cout << p << endl;
	//	strncpy(p, replacer, 3);
	//}
	return s;
*/

/*
	while ((p = strchr(s + pos1, c1)) )//&& strlen(p) > 1)// && (p != strchr(s + pos1 + 1, c1)))
	//p = strchr(s + pos1, c1);
	//while (strlen(p) > 1)
	{
		//cout << p << endl;
		//cout << "s:" << s << " s[0]: " << s[0] << " p-s+1: " << p - s + 1 << " s[p-s]: " << s[p - s + 1] << endl;
		//if ((s[p - s] == c1) && (s[p - s + 1] == c2))
		if (s[p - s + 1] == c2)
		{
			//cout << " : " << s[p - s] << endl;
			pos2 = p - s + 2;
			//cout << " t= " << t << " s= " << s << " pos1= " << pos1 << " pos2= " << pos2 << endl;
			strncat(t, s + pos1, pos2 - pos1 - 2);
			//cout << " t= " << t << " s= " << s << " pos1= " << pos1 << " pos2= " << pos2 << endl;
			//cout << "2t= " << t << " s= " << s << " pos1= " << pos1 << " pos2= " << pos2 << endl;
			strcat(t, "***");
			//cout << " t= " << t << " s= " << s << " pos1= " << pos1 << " pos2= " << pos2 << endl;
			//cout << "3t= " << t << " s= " << s << " pos1= " << pos1 << " pos2= " << pos2 << endl;
			//pos1 = pos2;
			pos1 = p - s + 1;
			//cout << " t= " << t << " s= " << s << " pos1= " << pos1 << " pos2= " << pos2 << endl;
		}
		//else {
		//	cout << p << endl;
//		cout << s << " : " << strchr(s + pos1, c1) << " : "  << strchr(s + pos1 + 1, c1) << endl;
		//	//pos2++;
		//	//pos1 = pos2;
		//	pos1++;
		//}
		//p = strchr(s + pos1, c1);
		//if (p == strchr(s + pos1 + 1, c1))
		//	break;

	}
	cout << "t=" << t << endl;
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
*/

}

//char* Change(char* str)
//{
//	if (strlen(str) < 2)
//		return str;
//	char* tmp = new char[strlen(str) * 4 / 2 + 1];
//	char* t = tmp;
//	tmp[0] = '\0';
//	int i = 0;
//	while (str[i + 1] != 0)
//	{
//		if ((str[i] == 'S' && str[i + 1] == 'Q') || (str[i] == 'Q' && str[i + 1] == 'S'))
//		{
//				strcat(t, "***");
//			t += 3;
//			i += 2;
//		}
//		else
//		{
//			*t++ = str[i++];
//			*t = '\0';
//		}
//	}
//	*t++ = str[i++];
//	*t++ = str[i++];
//	*t = '\0';
//	strcpy(str, tmp);
//	return tmp;
//}

int main()
{



	char str[128] = "aSQbQScSQdQSesqqs.";

	//cout << "Enter string : ";
	//cin.getline(str, 128);

	cout << "String contained " << Count(str) << " groups of 'SQ' or 'QS'" << endl;

	char* dest1 = new char[128];
	//char* dest2 = new char[128];
	dest1 = Change(str);
	//dest2 = Change(str, "QS");
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest1 << endl;
	//cout << "Modified string (result): " << dest2 << endl;

	////*str = *dest1;
	//dest2 = Change(dest1, 'Q', 'S');

	////cout << "Modified string (param) : " << str << endl;
	////if (dest2)
	//	cout << "Modified string (result): " << dest2 << endl;
	////else
	//	cout << "Modified string (result): " << dest1 << endl;

	return 0;
}
