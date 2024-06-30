// Copyright (C) 2024 Ethan Cheng <ethan@nijika.org>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 3 of the License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

const unsigned char ascii_table[128][3] = {
	{4,1,0}, // 0x00 NUL
	{4,1,0}, // 0x01 SOH
	{4,1,0}, // 0x02 STX
	{4,1,0}, // 0x03 ETX
	{4,1,0}, // 0x04 EOT
	{4,1,0}, // 0x05 ENQ
	{4,1,0}, // 0x06 ACK
	{4,1,0}, // 0x07 BEL
	{1,2,0}, // 0x08 BS
	{4,1,0}, // 0x09 HT
	{1,6,0}, // 0x0A LF
	{4,1,0}, // 0x0B VT
	{4,1,0}, // 0x0C FF
	{1,6,0}, // 0x0D CR
	{4,1,0}, // 0x0E SO
	{4,1,0}, // 0x0F SI
	{4,1,0}, // 0x10 DLE
	{4,1,0}, // 0x11 DC1
	{4,1,0}, // 0x12 DC2
	{4,1,0}, // 0x13 DC3
	{4,1,0}, // 0x14 DC4
	{4,1,0}, // 0x15 NAK
	{4,1,0}, // 0x16 SYN
	{4,1,0}, // 0x17 ETB
	{4,1,0}, // 0x18 CAN
	{4,1,0}, // 0x19 EM
	{4,1,0}, // 0x1A SUB
	{4,1,0}, // 0x1B ESC
	{4,1,0}, // 0x1C FS
	{4,1,0}, // 0x1D GS
	{4,1,0}, // 0x1E RS
	{4,1,0}, // 0x1F US
	{1,7,0}, // 0x20 SPACE
	{7,5,1}, // 0x21 !
	{2,7,1}, // 0x22 "
	{7,4,1}, // 0x23 #
	{6,4,1}, // 0x24 $
	{7,2,1}, // 0x25 %
	{7,3,1}, // 0x26 &
	{2,7,0}, // 0x27 '
	{7,0,1}, // 0x28 (
	{6,0,1}, // 0x29 )
	{6,3,1}, // 0x2A *
	{6,1,1}, // 0x2B +
	{7,7,0}, // 0x2C ,
	{7,1,0}, // 0x2D -
	{6,7,0}, // 0x2E .
	{7,6,0}, // 0x2F /
	{6,0,0}, // 0x30 0
	{7,5,0}, // 0x31 1
	{6,5,0}, // 0x32 2
	{7,4,0}, // 0x33 3
	{6,4,0}, // 0x34 4
	{7,2,0}, // 0x35 5
	{6,2,0}, // 0x36 6
	{7,3,0}, // 0x37 7
	{6,3,0}, // 0x38 8
	{7,0,0}, // 0x39 9
	{4,7,1}, // 0x3A :
	{4,7,0}, // 0x3B ;
	{3,6,0}, // 0x3C <
	{6,1,0}, // 0x3D =
	{5,2,0}, // 0x3E >
	{7,6,1}, // 0x3F ?
	{6,5,1}, // 0x40 @
	{2,6,1}, // 0x41 A
	{3,0,1}, // 0x42 B
	{4,0,1}, // 0x43 C
	{2,3,1}, // 0x44 D
	{5,5,1}, // 0x45 E
	{4,5,1}, // 0x46 F
	{2,5,1}, // 0x47 G
	{4,4,1}, // 0x48 H
	{3,2,1}, // 0x49 I
	{2,4,1}, // 0x4A J
	{4,2,1}, // 0x4B K
	{2,2,1}, // 0x4C L
	{3,1,1}, // 0x4D M
	{5,1,1}, // 0x4E N
	{5,3,1}, // 0x4F O
	{3,3,1}, // 0x50 P
	{5,6,1}, // 0x51 Q
	{3,5,1}, // 0x52 R
	{4,3,1}, // 0x53 S
	{5,4,1}, // 0x54 T
	{5,2,1}, // 0x55 U
	{5,0,1}, // 0x56 V
	{3,6,1}, // 0x57 W
	{4,1,1}, // 0x58 X
	{3,4,1}, // 0x59 Y
	{4,6,1}, // 0x5A Z
	{3,7,1}, // 0x5B [
	{4,1,0}, // 0x5C BACKSLASH
	{3,7,0}, // 0x5D ]
	{4,1,0}, // 0x5E ^
	{7,1,1}, // 0x5F _
	{4,1,0}, // 0x60 `
	{2,6,0}, // 0x61 a
	{3,0,0}, // 0x62 b
	{4,0,0}, // 0x63 c
	{2,3,0}, // 0x64 d
	{5,5,0}, // 0x65 e
	{4,5,0}, // 0x66 f
	{2,5,0}, // 0x67 g
	{4,4,0}, // 0x68 h
	{3,2,0}, // 0x69 i
	{2,4,0}, // 0x6A j
	{4,2,0}, // 0x6B k
	{2,2,0}, // 0x6C l
	{3,1,0}, // 0x6D m
	{5,1,0}, // 0x6E n
	{5,3,0}, // 0x6F o
	{3,3,0}, // 0x70 p
	{5,6,0}, // 0x71 q
	{3,5,0}, // 0x72 r
	{4,3,0}, // 0x73 s
	{5,4,0}, // 0x74 t
	{5,2,0}, // 0x75 u
	{5,0,0}, // 0x76 v
	{3,6,0}, // 0x77 w
	{4,1,0}, // 0x78 x
	{3,4,0}, // 0x79 y
	{4,6,0}, // 0x7A z
	{4,1,0}, // 0x7B {
	{4,1,0}, // 0x7C |
	{4,1,0}, // 0x7D }
	{4,1,0}, // 0x7E ~
	{4,1,0}, // 0x7F DEL
};

const unsigned char input_table[8] = {A0, A1, A2, A3, A4, A5, A6, A7};
const unsigned char output_table[8] = {2, 3, 4, 5, 6, 7, 8, 9};

unsigned short column = 1;
unsigned short delay_char = 100;
bool escape = false;

void writeMatrix(unsigned char input, unsigned char output);
void writeMatrix(unsigned char mod_input, unsigned char mod_output,
                 unsigned char input, unsigned char output);
void writeChar(unsigned char c);

void setup()
{
	for (int i = 0; i < 8; i++)
		pinMode(input_table[i], INPUT_PULLUP);

	for (int i = 0; i < 8; i++) {
		pinMode(output_table[i], OUTPUT);
		digitalWrite(output_table[i], LOW);
	}

	Serial.begin(9600, SERIAL_8N1);
	Serial.setTimeout(100);
	Serial.println("READY");
}

void loop()
{
	if (Serial.available() > 0) {
		unsigned char ch = Serial.read();

		/*
		// check for ansi escape sequence
		if (ch == '[' && escape) {
			escape = false;
			escape_handler();
		} else if (ch == 0x1b) {
			escape = true;
		} else {
			escape = false;
		}
		*/

		writeChar(ch);
		Serial.write(ch);

		if (ch == '\n') {
			delay(35*column + 200);
			column = 1;
		} else {
			column++;
		}

		//delay(delay_char);
	}
}

void writeMatrix(unsigned char input, unsigned char output)
{
	if (input >= 8 || output >= 8)
		return;

	// temporary hack because inputs 6 and 7 don't work
	unsigned char delay_ms = 0;
	if (input == 7) {
		input = 0;
		delay_ms = 3;
	} else if (input == 6) {
		input = 0;
		delay_ms = 5;
	}

	input = input_table[input];
	output = output_table[output];

	for (int i = 0; i < 10;) {
		if (digitalRead(input) == LOW) {
			if (delay_ms > 0)
				delay(delay_ms);
			digitalWrite(output, HIGH);
			delay(1);
			digitalWrite(output, LOW);
			i++;
		}
	}
}

void writeMatrix(unsigned char mod_input, unsigned char mod_output,
                 unsigned char input, unsigned char output)
{
	if (mod_input >= 2 || mod_output >= 8 || input >= 8 || output >= 8)
		return;

	unsigned char delay_ms;
	if (mod_input == input) {
		delay_ms = 0;
	} else {
		unsigned char diff;
		if (mod_input > input)
			diff = mod_input - input;
		else
			diff = input - mod_input;
		diff = 8 - diff;

		delay_ms = diff * 2;
	}

	mod_input = input_table[mod_input];
	mod_output = output_table[mod_output];
	input = input_table[input];
	output = output_table[output];

	for (int i = 0; i < 10;) {
		if (digitalRead(mod_input) == LOW) {
			digitalWrite(mod_output, HIGH);
			delay(1);
			digitalWrite(mod_output, LOW);
			i++;
		}
	}

	for (int i = 0; i < 10;) {
		if (digitalRead(mod_input) == LOW) {
			if (delay_ms == 0) {
				digitalWrite(mod_output, HIGH);
				digitalWrite(output, HIGH);
				delay(1);
				digitalWrite(mod_output, LOW);
				digitalWrite(output, LOW);
			} else {
				digitalWrite(mod_output, HIGH);
				delay(1);
				digitalWrite(mod_output, LOW);

				delay(delay_ms);

				digitalWrite(output, HIGH);
				delay(1);
				digitalWrite(output, LOW);
			}
			i++;
		}
	}
}

void writeChar(unsigned char c)
{
	if (c >= 128)
		return;

	unsigned char input = ascii_table[c][0];
	unsigned char output = ascii_table[c][1];

	if (ascii_table[c][2])
		writeMatrix(0, 7, input, output); // SHIFT
	else if (c == '<' || c == '>' || c == '\r')
		writeMatrix(1, 0, input, output); // CODE
	else
		writeMatrix(input, output);
}


