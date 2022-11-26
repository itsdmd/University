// Same as w04 but implement Factory method

using System;
using System.IO;
using System.Text;

abstract class IRule
{
	public abstract string Renamer(string inp);

	protected string _ruleName = "";
	public abstract void Logging();
}

class AddPrefix: IRule
{
	public string _prefix;

	public AddPrefix(string prefix) => _prefix = prefix;

	public override string Renamer(string inp)
	{
		return (new StringBuilder(_prefix)
					.Append(" ")
					.Append(inp)
					.ToString());
	}

	public override void Logging() => Console.WriteLine($"AddPrefix: {_prefix}");
}

class OneSpace: IRule
{
	public override string Renamer(string inp)
	{
		return (string.Join(" ", inp.Split(" ", StringSplitOptions.RemoveEmptyEntries)));
	}

	public override void Logging() => Console.WriteLine($"OneSpace");
}

class PascalCase: IRule
{
	public override string Renamer(string inp)
	{
		List<string> _words = inp.Split(' ').ToList();
		StringBuilder _res = new StringBuilder();

		foreach (string word in _words)
		{
			if (word.Length > 0)
			{
				_res.Append(word.Substring(0, 1).ToUpper())
					.Append(word.Substring(1))
					.Append(" ");
			}
		}

		return (_res.ToString());
	}

	public override void Logging() => Console.WriteLine($"PascalCase");
}

class Replace: IRule
{
	static string _from = "";
	static string _to = "";

	public Replace(string from, string to)
	{
		_from = from;
		_to = to;
	}

	public override string Renamer(string inp)
	{
		return (inp.Replace(_from, _to));
	}

	public override void Logging() => Console.WriteLine($"Replace: {_from} -> {_to}");
}

class Formatter
{
	private static string _ruleFile = new string("");
	private static string _fileName = new string("");

	public string ruleFile { set { _ruleFile = value; } }
	public string fileName { set { _fileName = value; } }
	public string formatted { get { return Renamer(); } }

	private IRule irule = null;

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
			var tokens = rule.Split(" ", StringSplitOptions.RemoveEmptyEntries);

			switch (tokens[0])
			{
				case "AddPrefix":
					irule = new AddPrefix(tokens[1]);
					break;
				
				case "OneSpaceOnly":
					irule = new OneSpace();
					break;
				
				case "PascalCase":
					irule = new PascalCase();
					break;
				
				case "Replace":
					irule = new Replace(tokens[1], tokens[3]);
					break;
				
				default:
					Console.WriteLine("WARNING: Invalid rule '" + rule + "'!");
					continue;
			}

			renamed = irule.Renamer(renamed);
			irule.Logging();
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
		renamedFiles.Add(fmt.formatted);

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