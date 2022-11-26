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
					dict.Add(type.Name.Replace("Rule", ""),
                                (IRule)Activator.CreateInstance(type));
                    
                    // Console.WriteLine();
                }
                
                // Console.WriteLine();
            }
        }

        return dict;
    }
}

class Factory
{
	private static string _ruleFile = new string("");
	private static string _fileName = new string("");

	public string ruleFile { set { _ruleFile = value; } }
	public string fileName { set { _fileName = value; } }
	public string renamed { get { return Parse(); } }

	// Read rule file
	static List<string> RuleReader()
	{
		return (new List<string>(File.ReadAllLines(_ruleFile)));
	}

	// Apply the rules
	public string Parse()
	{
		List<string> rules = RuleReader();
		string renamed = new string(_fileName);

        Dictionary<string, IRule> rulePrototypes = new DLLReader().GetPluginDict();

		foreach (string rule in rules)
		{
			List<string> tokens = rule.Split(" ", StringSplitOptions.RemoveEmptyEntries).ToList();
            IRule irule = null;

            try
            {
                irule = rulePrototypes[tokens[0]];
            }
            catch (KeyNotFoundException)
            {
                Console.WriteLine("Error: " + tokens[0] + " is not a valid rule.");
                continue;
            }

            irule.Parse = tokens;
			renamed = irule.Rename(renamed);
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

        Factory fmt = new Factory();
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