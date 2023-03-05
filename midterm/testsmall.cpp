/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: testsmall.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
																				NOTHING CAN BE CHANGED IN THIS FILE
																				DO NOT POST THIS FILE IN CANVAS
																				WE WILL USE DIFFERENT TEST FOR GRAING
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
ONLY INCLUDE HERE. YOU CANNOT ADD ANYTHING HEREe
-----------------------------------------------------------------*/
#include "longnumber.h"
static int marks = 5;

/*--------------------------------------------------------
long number class
----------------------------------------------------------*/
class testsmall {
public:
	testsmall() {
		small_test_();
	}

private:
	void small_test_();
	void test_add_(const int a, const int b, const int ans, bool display = true);
	void test_add_(const char* a, const char* b, const char* ans, bool display = true);
	void test_multiply_(const int  a, const int  b, const int ans, bool display = true);
	void test_multiply_(const char* a, const int  b, const char* ans, bool display = true);
	void test_factorial_(int n, const char* s);
};

/*----------------------------------------------------------------
small test
-----------------------------------------------------------------*/
void testsmall::small_test_() {
	cout << "------------------  small tests starts ----------------\n";
	cout << "Your marks so for " << marks << endl;
#if 1
	{
		int k = -1986;
		const char* n = "1986";
		longnumber l(k);
		cout << "l(unsigned int) = " << l << endl;
		assert(l.is_negative());
		assert(!(l.is_positive()));
		int start = 0;
		int d = l.num_digits();
		for (int i = 0; i < d; ++i) {
			int c = l[i] - '0';
			int rc = n[i + start] - '0';
			assert(c == rc);
		}
		longnumber l1(k);
		longnumber l2(-k);
		assert(l == l1);
		assert(l != l2);
		marks += 5;
		cout << "Your marks so for " << marks << endl;
	}
#endif
#if 1
	{
		const char* n = "-123567890123567890123567890123567890123567890123567890123567890";
		longnumber l(n);
		cout << "l(const char* n) = " << l << endl;
		assert(l.is_negative());
		assert(!(l.is_positive()));
		int start = 1;
		int d = l.num_digits();
		for (int i = 0; i < d; ++i) {
			int c = l[i] - '0';
			int rc = n[i + start] - '0';
			assert(c == rc);
		}
		marks += 5;
		cout << "Your marks so for " << marks << endl;
	}
#endif

#if 1
	{
		test_add_(1986, 19, (1986 + 19));
		marks += 5;
		cout << "Your marks so for " << marks << endl;
	}
#endif

#if 1
	{
		test_add_("99", "1", "100");
		marks += 5;
		cout << "Your marks so for " << marks << endl;
	}
#endif
#if 1
	{
		test_multiply_(1986, 19, (1986 * 19));
		marks += 5;
		cout << "Your marks so for " << marks << endl;
	}
#endif
#if 1
	{
		test_multiply_("89977", 46, "4138942");
		marks += 5;
		cout << "Your marks so for " << marks << endl;
	}
#endif
#if 1
	{
		const char* a = "3628800";
		test_factorial_(10, a);
		marks += 15;
		cout << "Your marks so for " << marks << endl;
	}
	cout << "I will make you suffer in real exam" << endl;
#endif

#if 1
	{
		test_add_(123, 0, 123);
		cout << "test add " << marks << endl;
	}
#endif
#if 1
	{
		test_add_(0, 0, 0);
		cout << "test add " << marks << endl;
	}
#endif
#if 1
	{
		test_add_("0", "0", "0");
		cout << "test add " << marks << endl;
	}
#endif
#if 1
	{
		test_add_("123", "0", "123");
		cout << "test add " << marks << endl;
	}
#endif
#if 1
	{
		test_multiply_("0", 0, "0");
		cout << "test multiple " << endl;
	}
#endif
#if 1
	{
		test_multiply_("0", 232, "0");
		cout << "test multiple " << endl;
	}
#endif
#if 1
	{
		test_multiply_("-11111111012312391738912739821739172983712837891273981", 232, "-2577777754856474883427755638643488132221378390775563592");
		cout << "test multiple " << endl;
	}
#endif
#if 1
	{
		test_multiply_("-111111110", 0, "0");
		cout << "test multiple " << endl;
	}
#endif
#if 1
	{
		const char* a = "402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		test_factorial_(1000, a);
		cout << "test fact" << endl;
	}
#endif
#if 1
	{
		const char* a = "1";
		test_factorial_(0, a);
		cout << "test fact" << endl;
	}
#endif
#if 1
	{
		const char* a = "1";
		test_factorial_(1, a);
		cout << "test fact" << endl;
	}
#endif
}


/*----------------------------------------------------------------
test add
-----------------------------------------------------------------*/
void testsmall::test_add_(const int  a, const int  b, const int ans, bool display) {
	longnumber c = a + b;
	if (c != ans || display) {
		cout << "-----------------------------------------------------\n";
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
		if (c != ans) {
			cout << "Expected ans was " << ans << endl;
			assert(false);
		}
	}
}

/*----------------------------------------------------------------
test add
-----------------------------------------------------------------*/
void testsmall::test_add_(const char* a, const char* b, const char* ans, bool display) {
	longnumber c = longnumber(a) + longnumber(b);
	longnumber lans = longnumber(ans);
	if (c != lans || display) {
		cout << "-----------------------------------------------------\n";
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;

		if (c != lans) {
			cout << "Expected ans was " << ans << endl;
			assert(false);
		}
	}
}

/*----------------------------------------------------------------
test mult
-----------------------------------------------------------------*/
void testsmall::test_multiply_(const int  a, const int  b, const int ans, bool display) {
	longnumber c = longnumber(a) * b;
	longnumber lans = longnumber(ans);
	if (c != lans || display) {
		cout << "-----------------------------------------------------\n";
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
		if (c != lans) {
			cout << "Expected ans was " << ans << endl;
			assert(false);
		}
	}
}

/*----------------------------------------------------------------
test mult
-----------------------------------------------------------------*/
void testsmall::test_multiply_(const char* a, const int  b, const char* ans, bool display) {
	longnumber c = longnumber(a) * b;
	longnumber lans = longnumber(ans);
	if (c != lans || display) {
		cout << "-----------------------------------------------------\n";
		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;
		if (c != lans) {
			cout << "Expected ans was " << ans << endl;
			assert(false);
		}
	}
}


/*----------------------------------------------------------------
test factorial
-----------------------------------------------------------------*/
void testsmall::test_factorial_(int n, const char* s) {
	longnumber ans(s);
	std::clock_t c_start = std::clock();
	longnumber a = longnumber::fact(n);
	std::clock_t c_end = std::clock();
	double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
	cout << "Factorial of " << n << " = " << endl;
	cout << a << endl;
	if (a != ans) {
		cout << "Expected ans was " << ans << endl;
	}
	cout << "CPU time used: " << time_elapsed_ms / 1000 << " seconds\n";
	assert(a == ans);
}


/*----------------------------------------------------------------
The main
-----------------------------------------------------------------*/
int main() {
#ifdef _WIN32
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	cout << "------- Start----------\n";
	testsmall l;
	cout << "------- END----------\n";
	return 0;
}
