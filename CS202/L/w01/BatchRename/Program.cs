using System;
using System.Collections.Generic;
using System.Text;

// 1. Replace some special characters into space: -  _
//For example: "jack-forsel-cv.pdf" ⇒ Should be "jack forsel cv.pdf" 

//2. The first letter of the word in the original filename should be in uppercase.
//For example: "jack  forsel  cv.pdf" ⇒ Should be "Jack  Forsel  Cv.pdf"

//3. Make sure there are no more than one spaces between words
//For example: "jack      forsel  cv.pdf" ⇒  Should be "jack forsel cv.pdf"

//4. Add a prefix of the current date to the file, in the format of YYMMDD
//For example: "jack forsel  cv.pdf" ⇒ Should be "210924 jack forsel cv.pdf"

namespace BatchRename
{
	class Program
	{
		static string Formatter(string inp){
			// Split file name into words
			char[] delimiterChars = { ' ', '-', '_' };
			string[] words = inp.Split(delimiterChars, StringSplitOptions.RemoveEmptyEntries);

			// Capitalize first character of each word
			for (int i = 0; i < words.Length; i++)
			{
				StringBuilder sb = new();
				sb.Append(words[i].Substring(0, 1).ToUpper())
				  .Append(words[i].AsSpan(1));
				
				words[i] = sb.ToString();
			}

			// Get the current date
			DateTime date = DateTime.Now;

			// Stitching
			StringBuilder builder = new(date.ToString("yyMMdd"));
			foreach (string word in words)
			{
				builder.Append(' ');
				builder.Append(word);
			}

			return builder.ToString();
		}

		static void Renamer(List<string> inp)
		{
			foreach(string name in inp)
			{
				Console.WriteLine(Formatter(name));
			}
		}

		static void Main()
		{
			List<string> filenames = new () { "Ernesto Lowe.pdf",
											  "Calvin-hopkins.pdf",
											  "Brandon    Mullins.pdf",
											  "Jon Wood.pdf",
											  "marianne-owers.pdf",
											  "Luis--Chavez.pdf",
											  "Cecil Logan.pdf",
											  "Saul_kennedy.pdf",
											  "Raul___Thompson___CV.pdf",
											  "Juana--Wagner.pdf",
											  "sophie_chapman.pdf",
											  "Donna___Mason.pdf",
											  "garry-roy.pdf",
											  "Drew sparks.pdf",
											  "Jeffrey norris.pdf",
											  "Dwayne_townsend.pdf",
											  "Violet-Garza.pdf",
											  "Oscar----Ellis.pdf",
											  "jeremiah wwest.pdf",
											  "emma    Padilla.pdf" };

			Console.WriteLine("File names after renaming:");
			Renamer(filenames);
		}
	}
}