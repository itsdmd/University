namespace BridgePattern
{
	internal abstract class AbstractController
	{
		protected IDevice _device;

		public AbstractController(IDevice device)
		{
			_device = device;
		}

		public abstract void TogglePower();
		public abstract void VolumeUp();
		public abstract void VolumeDown();
		public abstract void ChannelUp();
		public abstract void ChannelDown();
	}
}