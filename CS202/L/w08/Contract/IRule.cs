namespace Contract
{
	public interface IRule
	{
		string Name { get; }
		List<string> Requirements { get; set; }
		string Rename(string inp);
	};
}