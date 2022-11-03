using Contract;

namespace AddPrefixRule
{
	public class AddPrefix : IRule
	{
		public string Name => "AddPrefix";

		private string _prefix = "";
		public List<string> Requirements
		{
			get => new List<string> { "prefix" };
			set => _prefix = value[0];
		}

		public string Rename(string inp)
		{
			return (_prefix + inp);
		}
	}
}