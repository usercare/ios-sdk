Pod::Spec.new do |s|
  s.name             = "UserCareSDK"
  s.version          = "1.0.16"
  s.summary          = "Official iOS client library for UserCare"
  s.description      = <<-DESC
  This is an Official iOS client library for UserCare. Seamless in-app customer service software that grows customer lifetime value.
                       DESC
  s.homepage         = "https://www.usercare.com/"
  s.license          = { :type => 'Commercial', :text => 'https://www.usercare.com/terms' }
  s.author           = { "UserCare" => "https://www.usercare.com" }
  s.source           = { :http => "https://cdn.usercare.com/files/usercare/sdk/downloads/ios/1.0.16/UserCareSDK-iOS-v1.0.16.zip" }
  s.platform         = :ios, '8.0'
  s.vendored_frameworks = "UserCareSDK.framework"
  s.requires_arc     = true
  s.frameworks       = 'CoreFoundation', 'WebKit', 'MobileCoreServices'
  s.weak_framework   = 'UserNotifications'
  s.libraries        = 'icucore', 'xml2'
end
