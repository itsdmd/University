using Contract;
using System.Reflection;        // retrieve information about assemblies, modules, members, parameters, and other entities in managed code by examining their metadata.

string folder = AppDomain.CurrentDomain.BaseDirectory;
DirectoryInfo folderInfo = new DirectoryInfo(folder);
var dllFiles = folderInfo.GetFiles("*.dll");

List<IPlugin> plugins = new List<IPlugin>();

foreach(var file in dllFiles)
{
	// Assembly: A compiled/binary file (*.dll, *.exe, etc.)
    var assembly = Assembly.LoadFrom(file.FullName);
    Console.WriteLine("\nLooking into " + file.Name);

	// Get all types inside the assembly
	// Type: Represents type declarations: class, interface, array, etc.
	var types = assembly.GetTypes();

    Console.WriteLine($"Found {types.Length} type(s):");

	foreach(var type in types)
    {
        Console.Write($"{type.Name}");

		if (type.IsClass									// If the type is a concrete class
			&& typeof(IPlugin).IsAssignableFrom(type))		// and it's compatible with IPlugin type
		{
			Console.Write("\t\t==> Compatible with " + typeof(IPlugin).Name);

			// Create an instance of this type,
			// cast its type to IPlugin
			// and add it to `plugins` for usage
			// if it isn't null
			plugins.Add((IPlugin)Activator.CreateInstance(type)!);
			
			Console.WriteLine();
		}
		
		Console.WriteLine();
    }
}

Console.WriteLine();

foreach (var f in plugins)
{
	Console.WriteLine(f.Calc(10, 2));
}