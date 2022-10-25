using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BridgePattern
{
	internal class RadioController : BaseController
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

		// Platform-specic methods
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
}
