NhaMay f = new NhaMay();


// Use dict: Simple, clunky to expand, requires re-compilation
var xeDict = new Dictionary<string, IXe>()
{
	{ "XeXang", new XeXang() },
	{ "XeDau", new XeDau() },
	{ "XeDien", new XeDien() }
};

string select_s = "XeXang";
IXe xe1 = xeDict[select_s];
xe1.Run();


// Use proto: Easier to expand, can be stored in DLL files and not require re-compilation
var mau1 = new XeXang();
var mau2 = new XeDau();
var mau3 = new XeDien();

var prototypes = new List<IXe>()
{
	mau1, mau2, mau3
};

NhaMay.CauHinh(prototypes);

var select_o = mau3.Name;
var xe2 = f.LapRap(select_o);
xe2.Run();



class NhaMay
{
	public NhaMay() {}

	public static Dictionary<string, IXe> _prototypes = new Dictionary<string, IXe>();

	public static void CauHinh(List<IXe> prototypes)
	{
		foreach(var xe in prototypes)
		{
			_prototypes.Add(xe.Name, xe);
		}
	}

	public IXe LapRap(string luachon)
	{
		return (IXe)_prototypes[luachon].Clone();
	}
}

interface IXe: ICloneable
{
	string Name { get; }

	void Run();
}

class XeXang : IXe
{
	public string Name => "XeXang";

	public object Clone()
	{
		return MemberwiseClone();
	}

	public void Run()
	{
		Console.WriteLine("Xe xang");
	}
}

class XeDau : IXe
{
	public string Name => "XeDau";

	public object Clone()
	{
		return MemberwiseClone();
	}

	public void Run()
	{
		Console.WriteLine("Xe dau");
	}
}

class XeDien : IXe
{
	public string Name => "XeDien";

	public object Clone()
	{
		return MemberwiseClone();
	}

	public void Run()
	{
		Console.WriteLine("Xe dien");
	}
}