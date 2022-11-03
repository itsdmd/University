using Contract;

namespace ReplaceRule
{
	public class Replace : IRule
	{
		public string Name => "Replace";

		private List<string> _reqs = new List<string>();
		private string _from = "";
		private string _to = "";

		public List<string> Parse
		{
			get => _reqs;
			set
			{
				_reqs = value;

				// _from take the second token until the word before '=>'
				_from = string.Join(" ", value.GetRange(1, value.IndexOf("=>") - 1));

				// _to take the words after '=>'
				_to = string.Join(" ", value.GetRange(value.IndexOf("=>") + 1, value.Count - value.IndexOf("=>") - 1));
			}
		}

		public string Rename(string inp)
		{
			return (inp.Replace(_from, _to));
		}
	};
}