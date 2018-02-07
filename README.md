<h1>Dancing LEDs</h1>
1) run do1.sh to generate test.txt<br />
2) edit out all the comments in test.txt<br />
3) cut and paste test.txt to what's in between<br /> 
	the curly brackets of buf[] = {...}<br />
	in main.c<br />
4) add up the (3) totals from test.txt and<br />
	use as define for 'TOTAL' in main.c<br />
5) then compile main.c with AVR compiler<br />
	and load to the ProMini<br />
<br />
<h2>topview pinout for ProMini with reset switch at bottom</h2>
<br />
#PD1		RAW<br />
#PD0		GND<br />
 PC6		PC6<br />
 GND		VCC<br />
#PD2		PC3<br />
#PD3		PC2<br />
#PD4		PC1<br />
#PD5		PC0<br />
#PD6		PB5<br />
#PD7		PB4<br />
 PB0		PB3<br />
 PB1		PCB2<br />
<br />
LEDs are connected to PORTD (marked as '#')<br />
<br />
<h2>patterns generated</h2>
<br />
<h3>test.cx:</h3>
<br />
fill from right<br />
clear from left<br />
fill from left<br />
clear from right<br />
fill from right<br />
clear from right<br />
fill from left<br />
clear from left<br />
single digit from right<br />
single digit from left<br />
single digit from left<br />
single digit from right<br />
single digit from left (3x)<br />
single digit from right (3x)<br />

<h3>test2.cx:</h3>

fill from right<br />
single digit from left (reverse)<br />
single digit from right (reverse)<br />
single digit from right (reverse)<br />
single digit from left (reverse)<br />
single digit from left (reverse 3x)<br />
single digit from right (reverse 3x)<br />
clear from left<br />
<br />
<h3>test3.cx:</h3>
<br />
stack from left<br />
stack from right<br />
stack from left (reverse)<br />
stack from right (reverse)<br />
<br />
sym pattern<br />
single digit from right w/ opp moving bit<br />
single digit from left w/ opp moving bit<br />
<br />
