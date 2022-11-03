namespace Contract
{
	public interface IRule
	{
		string Name { get; }
		List<string> Parse { get; set; }
		string Rename(string inp);
	};
}