using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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

	internal class BasicController : AbstractController
	{
		public BasicController(IDevice device) : base(device) { }

		public override void TogglePower()
		{
			if (_device.IsEnabled())
			{
				_device.Disable();
			}
			else
			{
				_device.Enable();
			}
		}

		public override void VolumeUp()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change volume. Device is disabled.");
				return;
			}

			if (_device.GetVolume() < 100)
			{
				_device.SetVolume(_device.GetVolume() + 10);
			}
			else
			{
				_device.SetVolume(100);
			}
		}

		public override void VolumeDown()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change volume. Device is disabled.");
				return;
			}

			if (_device.GetVolume() > 10)
			{
				_device.SetVolume(_device.GetVolume() - 10);
			}
			else
			{
				_device.SetVolume(0);
			}
		}

		public override void ChannelUp()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}
			
			_device.SetChannel(_device.GetChannel() + 1);
		}

		public override void ChannelDown()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}
			
			_device.SetChannel(_device.GetChannel() - 1);
		}
	}

	internal class TVController : BasicController
	{
		public TVController(IDevice device) : base(device) { }

		public override void ChannelUp()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}
			
			if (_device.GetChannel() == _device.GetLimits()["CHN_MAX"])
			{
				_device.SetChannel(_device.GetLimits()["CHN_MIN"]);
			}
			else
			{
				_device.SetChannel(_device.GetChannel() + 1);
			}
		}
		
		public override void ChannelDown()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}
			
			if (_device.GetChannel() == _device.GetLimits()["CHN_MIN"])
			{
				_device.SetChannel(_device.GetLimits()["CHN_MAX"]);
			}
			else
			{
				_device.SetChannel(_device.GetChannel() - 1);
			}
		}

		public void Mute()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change volume. Device is disabled.");
				return;
			}

			_device.SetVolume(0);
		}
	}

	internal class RadioController : BasicController
	{
		public RadioController(IDevice device) : base(device) { }

		public override void ChannelUp()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}

			uint newFrequency = _device.GetChannel();
			Dictionary<string, uint> radioConsts = _device.GetLimits();

			newFrequency += radioConsts["CHN_STEP"];
			if (_device.GetChannel() > radioConsts["CHN_MAX"])
			{
				newFrequency = radioConsts["CHN_MIN"];
			}

			_device.SetChannel(newFrequency);
		}
		
		public override void ChannelDown()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}

			uint newFrequency = _device.GetChannel();
			Dictionary<string, uint> radioConsts = _device.GetLimits();

			if (_device.GetMode() == "FM")
			{
				newFrequency -= radioConsts["FM_STEP"];
				if (_device.GetChannel() < radioConsts["FM_MIN"])
				{
					newFrequency = radioConsts["FM_MAX"];
				}
			}
			else
			{
				newFrequency -= radioConsts["AM_STEP"];
				if (_device.GetChannel() < radioConsts["AM_MIN"])
				{
					newFrequency = radioConsts["AM_MAX"];
				}
			}

			_device.SetChannel(newFrequency);
		}

		public void ToggleFM()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change mode. Device is disabled.");
				return;
			}

			switch (_device.GetMode())
			{
				case "FM":
					_device.SetMode("AM");
					break;
				case "AM":
					_device.SetMode("FM");
					break;
				default:
					_device.Log("Device does not have FM functionality. Unable to change mode.");
					return;
			}
		}
	}

	internal class TechnicianController : BasicController
	{
		public TechnicianController(IDevice device) : base(device) { }

		public void SetName(string name)
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change property. Device is disabled.");
				return;
			}

			_device.SetName(name);
		}

		public void SetChannel(uint channel)
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot change channel. Device is disabled.");
				return;
			}
			
			_device.SetChannel(channel);
		}

		public void GetLimits()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Cannot display values. Device is disabled.");
				return;
			}
			
			Dictionary<string, uint> limits = _device.GetLimits();
			foreach (KeyValuePair<string, uint> kvp in limits)
			{
				Console.WriteLine(kvp.Key + " = " + kvp.Value);
			}
		}

		public void RestartDevice()
		{
			if (_device.IsEnabled() == false)
			{
				_device.Log("Device is already disabled.");
				return;
			}
			
			_device.Disable();
			_device.Enable();
		}
	}
}
