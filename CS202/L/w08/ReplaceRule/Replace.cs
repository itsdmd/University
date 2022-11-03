using Contract;

namespace ReplaceRule
{
	public class Replace : IRule
	{
		public string Name => "Replace";

		private string _from = "";
		private string _to = "";

		public List<string> Requirements
		{
			get => new List<string> { "from", "to" };
			set
			{
				_from = value[0];
				_to = value[1];
			}
		}

		public string Rename(string inp)
		{
			return (inp.Replace(_from, _to));
		}
	};
}