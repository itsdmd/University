using Contract;
using System.Text;
using System.Reflection;        // retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata.


class DLLReader
{
    public Dictionary<string, IRule> GetPluginDict()
	{
		string folder = AppDomain.CurrentDomain.BaseDirectory;
		DirectoryInfo folderInfo = new DirectoryInfo(folder);
		var dllFiles = folderInfo.GetFiles("*.dll");
		
		Dictionary<string, IRule> dict = new Dictionary<string, IRule>();

        foreach(var file in dllFiles)
        {
            var assembly = Assembly.LoadFrom(file.FullName);
            // Console.WriteLine("\nLooking into " + file.Name);

            var types = assembly.GetTypes();

            // Console.WriteLine($"Found {types.Length} type(s):");

            foreach(var type in types)
            {
                // Console.Write($"{type.Name}");

                if (type.IsClass
                    && typeof(IRule).IsAssignableFrom(type))
                {
					// Console.Write("\t\t==> Compatible with " + typeof(IRule).Name);

					// Remove "Rule" from the name
					dict.Add(type.Name.Replace("Rule", ""), (IRule)Activator.CreateInstance(type));
                    
                    // Console.WriteLine();
                }
                
                // Console.WriteLine();
            }
        }

        return dict;
    }
}

class Formatter
{
	private static string _ruleFile = new string("");
	private static string _fileName = new string("");

	public string ruleFile { set { _ruleFile = value; } }
	public string fileName { set { _fileName = value; } }
	public string renamed { get { return Renamer(); } }

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

        Dictionary<string, IRule> plugins = new DLLReader().GetPluginDict();

		foreach (string rule in rules)
		{
			var tokens = rule.Split(" ", StringSplitOptions.RemoveEmptyEntries);
            var reqs = new List<string>();
            IRule plugin = null;

            try
            {
                plugin = plugins[tokens[0]];
            }
            catch (KeyNotFoundException)
            {
                Console.WriteLine("Error: " + tokens[0] + " is not a valid rule.");
                continue;
            }

			switch (tokens[0])
			{
				case "AddPrefix":
					reqs.Add(tokens[1]);
					break;

				case "Replace":
                    // FromString starts after tokens[0] and end when encounter ' ='
                    reqs.Add(rule.Substring(rule.IndexOf(tokens[0]) + tokens[0].Length + 1,
                                            rule.IndexOf(" =") - rule.IndexOf(tokens[0]) - tokens[0].Length - 1));
					// ToString starts after '>' until end of string
					reqs.Add(rule.Substring(rule.IndexOf('>') + 1));
					break;

				default:
                    break;
			}

            plugin.Requirements = reqs;
			renamed = plugin.Rename(renamed);
		}

		return renamed;
	}
}

class MainApp
{
    static void Main()
    {
        List<string> files = new List<string>();
        List<string> renamedFiles = new List<string>();

        files.Add("Michael      jack-forsel google.pdf");

        Formatter fmt = new Formatter();
        fmt.ruleFile = "CVRules.txt";
        fmt.fileName = files[0];

        renamedFiles.Add(fmt.renamed);

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