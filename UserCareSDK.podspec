Pod::Spec.new do |s|
  s.name             = "UserCareSDK"
  s.version          = "1.0.5"
  s.summary          = "Official iOS client library for UserCare"
  s.description      = <<-DESC
  This is an Official iOS client library for UserCare. Seamless in-app customer service software that grows customer lifetime value.
                       DESC
  s.homepage         = "https://www.usercare.com/"
  s.license          = 'Commercial'
  s.author           = { "UserCare" => "https://www.usercare.com" }
  s.source           = { :http => "https://www.usercare.com" }
  s.platform     = :ios, '8.0'
  s.vendored_frameworks = "UserCareSDK.framework"
  s.requires_arc = true
  s.frameworks = 'CoreFoundation'
  s.libraries = 'icucore'
  #s.xcconfig = { "OTHER_LDFLAGS" => "-ObjC" }
end
