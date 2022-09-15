using System;
using System.Globalization;
using System.Text;

namespace PersonalFinanceAdvisor
{
	class Program
	{
		static Tuple<float, float, float, float, float, float> JARS(float income)
		{
			float[] distro = new float[6] { (0.55f * income),	// Neccessities
											(0.1f * income),	// Long-term
											(0.1f * income),    // Play
											(0.1f * income),    // Education
											(0.1f * income),    // Financial
											(0.05f * income) };	// Give

			Tuple<float, float, float, float, float, float> jars = new( distro[0], distro[1], distro[2],
																		distro[3], distro[4], distro[5] );
			
			return jars;
		}
		
		static void Main()
		{
			// Ask for user's monthly income
			float income = 0f;
			do
			{
				Console.WriteLine("Enter your monthly income:");
				string usrInp = new(Console.ReadLine());

				// Parse input to number
				income = float.Parse(usrInp, CultureInfo.InvariantCulture.NumberFormat);
			} while (income <= 0);
			
			Tuple<float, float, float, float, float, float> jars = JARS(income);

			// Print out JARS
			Console.WriteLine("Your JARS are:");

			// https://www.csharp-examples.net/string-format-double/
			Console.WriteLine("Neccessities: ".PadLeft(15)	+ string.Format("{0:0,0.###}", jars.Item1));
			Console.WriteLine("Long-term: ".PadLeft(15)		+ string.Format("{0:0,0.###}", jars.Item2));
			Console.WriteLine("Play: ".PadLeft(15)			+ string.Format("{0:0,0.###}", jars.Item3));
			Console.WriteLine("Education: ".PadLeft(15)		+ string.Format("{0:0,0.###}", jars.Item4));
			Console.WriteLine("Financial: ".PadLeft(15)		+ string.Format("{0:0,0.###}", jars.Item5));
			Console.WriteLine("Give: ".PadLeft(15)			+ string.Format("{0:0,0.###}", jars.Item6));
		}
	}
}