using Contract;

namespace AddPrefixRule
{
	public class AddPrefix : IRule
	{
		public string Name => "AddPrefix";

		private string _prefix = "";
		public List<string> Parse
		{
			get => new List<string> { "prefix" };
			set => _prefix = value[1];
		}

		public string Rename(string inp)
		{
			return (_prefix + " " + inp);
		}
	}
}