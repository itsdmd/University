// There are four types of Renaming rule

//1. Replace special characters into space: -_ [[ReplaceWithSpace (= SpecChars + Replacer)]]
//For example: "jack-forsel-cv.pdf" ⇒ Should be "jack forsel cv.pdf"

//2. The first letter of the word in the original filename should be in uppercase. [[TitleCase]]
//For example: "jack  forsel  cv.pdf" ⇒ Should be "Jack  Forsel  Cv.pdf"

//3. Make sure there are no more than one space between words [[OneSpaceOnly]]
//For example: "jack    forsel        cv.pdf" ⇒  Should be "jack forsel cv.pdf"

//4. Add a prefix of the current date to the file, in the format of YYMMDD [[AddDatePrefix (= FormattedDate + AddPrefix)]]
//For example: "jack forsel  cv.pdf" ⇒ Should be "210924 jack forsel cv.pdf"

using System;
using System.IO;
using System.Text;

class Formatter
{
	private static string _ruleFile = new string("");
	private static string _fileName = new string("");
	public string ruleFile { set { _ruleFile = value; } }
	public string fileName { set { _fileName = value; } }

	public string Formatted { get { return Renamer(); } }

	// === Modules ===
	static string Replacer(string inp, string from, string to)
	{
		return (inp.Replace(from, to));
	}

	static string Replacer(string inp, List<string> froms, string to)
	{
		foreach (string from in froms)
		{
			inp = Replacer(inp, from, to);
		}

		return (inp);
	}

	static string TitleCase(string inp)
	{
		string[] words = inp.Split(' ');
		string res = "";
		foreach (string word in words)
		{
			res += word.Substring(0, 1).ToUpper() + word.Substring(1) + " ";
		}
		return (res.Trim());
	}

	static string OneSpaceOnly(string inp)
	{
		// Replace multiple spaces to one
		return (string.Join(" ", inp.Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries)));
	}

	static string AddPrefix(string inp, string prefix)
	{
		// Add prefix to the file's name using builder
		return (new StringBuilder(prefix)
					.Append(" ")
					.Append(inp)
					.ToString());
	}

	static string FormattedDate()
	{
		// Get current date in the format of YYMMDD
		return (DateTime.Now.ToString("yyMMdd"));
	}
	// =================

	// Read rule file
	static List<string> RuleReader()
	{
		return (new List<string>(File.ReadAllLines(_ruleFile)));
	}

	// Apply the rules
	public string Renamer()
	{
		List<string> rules = RuleReader();
		string renamed = new string(_fileName);

		foreach (string rule in rules)
		{
			var tokens = rule.Split(new string[] { " " }, StringSplitOptions.RemoveEmptyEntries);

			switch (tokens[0])
			{
				case "Replace":
					renamed = Replacer(renamed, tokens[1], tokens[3]);
					 // Console.WriteLine("Rule 'Replace' applied: " + renamed);
					break;
				
				case "ReplaceWithSpace":
					List<string> specChars = new List<string>();
					for (int i = 1; i < tokens.Length; i++)
						specChars.Add(tokens[i]);
					renamed = Replacer(renamed, specChars, " ");
					// Console.WriteLine("Rule 'ReplaceWithSpace' applied: " + renamed);
					break;
				
				case "TitleCase":
					renamed = TitleCase(renamed);
					// Console.WriteLine("Rule 'TitleCase' applied: " + renamed);
					break;
				
				case "OneSpaceOnly":
					renamed = OneSpaceOnly(renamed);
					// Console.WriteLine("Rule 'OneSpaceOnly' applied: " + renamed);
					break;
				
				case "AddPrefix":
					renamed = AddPrefix(renamed, tokens[1]);
					// Console.WriteLine("Rule 'AddPrefix' applied: " + renamed);
					break;
				
				case "AddDatePrefix":
					renamed = AddPrefix(renamed, FormattedDate());
					// Console.WriteLine("Rule 'AddDatePrefix' applied: " + renamed);
					break;
				
				default:
					Console.WriteLine("WARNING: Invalid rule '" + rule + "'!");
					break;
			}
		}

		return renamed;
	}
}

class RenameRuleSerialization
{
	//readonly static string targetDir = $"{AppDomain.CurrentDomain.BaseDirectory}files";

	static void Main()
	{
		//List<string> fullDirs = new List<string>(Directory.GetFiles(targetDir));	// Full directory path of files
		List<string> files = new List<string>();                                    // List of files' name
		List<string> renamedFiles = new List<string>();

		// TODO: Hard-coded paragraph for testing. Remove when dealing with directories.
		files.Add("Michael      jack-forsel google.pdf");
		Formatter fmt = new Formatter();
		fmt.ruleFile = "CVRules.txt";
		fmt.fileName = files[0];
		renamedFiles.Add(fmt.Formatted);

		//foreach (string dir in fullDirs)
		//{
		//	string fileName = Path.GetFileName(dir).ToString();
		//	files.Add(fileName);
		//	fmt.fileName = fileName;
		//	renamedFiles.Add(fmt.Formatted);
		//}

		Console.WriteLine("\nDone! Result(s):");
		for (int i = 0; i < files.Count; i++)
		{
			StringBuilder sb = new StringBuilder();

			sb.Append(files[i])
			  .Append(" => ")
			  .Append(renamedFiles[i]);
			
			Console.WriteLine(sb.ToString());
		}
	}
}