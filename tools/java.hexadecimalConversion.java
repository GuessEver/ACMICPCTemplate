import java.io.*;
import java.util.*;
import java.math.*;
// Binary, Octal, Decimal(Integer/BigInteger), Hexadecimal
public class Main{
	public static void main(String args[])
	{
		//Decimal(123) to Others
		String a1 = Integer.toBinaryString(123);
		String a2 = Integer.toOctalString(123);
		String a3 = Integer.toHexString(123);
		//Others to Decimal(123)
		int b1 = Integer.valueOf("1111011", 2);
		int b2 = Integer.valueOf("173", 8);
		int b3 = Integer.valueOf("7b", 16);
		// Others to BigInteger(Decimal(123))
		BigInteger c1 = new BigInteger("1111011", 2);
		BigInteger c2 = new BigInteger("173", 8);
		BigInteger c3 = new BigInteger("7B", 16);
	}
}
