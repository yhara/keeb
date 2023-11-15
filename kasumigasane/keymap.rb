kbd = Keyboard.new
kbd.init_direct_pins([2, 3, 4, 5, 6, 7, 8, 9, 29, 28, 27, 26, 22, 20, 23, 21])
# ~ KC_PLUS
# ^ KC_EQL
# + 
# = KC_UNDS

kbd.add_layer :default, %i[
  KC_7 KC_8 KC_9 KC_BSPC
  KC_4 KC_5 KC_6 KC_ENT
  KC_1 KC_2 KC_3 KC_COLON
  KC_0 KC_DOT KC_COLON MACRO_1
#  KC_7 KC_8 KC_9 KC_BSPC
#  KC_4 KC_5 KC_6 KC_ENT
#  KC_1 KC_2 KC_3 KC_COLON
#  KC_0 KC_DOT KC_COLON KC_UNDS
]

#class RGB
#  def show
#    if @offed
#      ws2812_fill(0, @pixel_size)
#      sleep 1
#      return
#    end
#    @ct ||= 0
#    @ct += 1
#    @ct = 1 if @ct > 16
#    (1..16).each do |i|
#      color =
#        if i != @ct then hsv2rgb(0,0,0)
#        elsif i%15 == 0 then hsv2rgb(0, @saturation, @max_value)
#        elsif i%5 == 0 then hsv2rgb(25, @saturation, @max_value)
#        elsif i%3 == 0 then hsv2rgb(50, @saturation, @max_value)
#        else 0
#        end
#      ws2812_set_pixel_at(i-1, color)
#    end
#    ws2812_show()
#    sleep_ms @delay
#  end
#end

rgb = RGB.new(
  1,    # pin number
  0,    # size of underglow pixel
  16,   # size of backlight pixel
  false # 32bit data will be sent to a pixel if true while 24bit if false
)

#rgb.add_pixel(0, 64)
#rgb.add_pixel(16, 64)
#rgb.add_pixel(32, 64)
#rgb.add_pixel(64, 64)
#rgb.add_pixel(64, 32)
#rgb.add_pixel(32, 32)
#rgb.add_pixel(16, 32)
#rgb.add_pixel(0, 32)
#rgb.add_pixel(0, 16)
#rgb.add_pixel(16, 16)
#rgb.add_pixel(32, 16)
#rgb.add_pixel(64, 16)
#rgb.add_pixel(0, 0)
#rgb.add_pixel(16, 0)
#rgb.add_pixel(32, 0)
#rgb.add_pixel(64, 0)

rgb.effect     = :breath
rgb.speed      = 22 #31  # 1-31  / default: 22
rgb.hue        = 0 # 0-100 / default: 0
rgb.saturation = 100 # 0-100 / default: 100
rgb.value      = 13  # 1-31  / default: 13

#kbd.define_mode_key, :CHLED, [Proc.new{rgb.hue = 50}, nil, 200, nil]
kbd.define_mode_key :MACRO_1, [ Proc.new { 
  #kbd.macro("Hello")
  puts "MACRO_1"
  #rgb.hue = 50 
}, nil, 200, nil]

kbd.append rgb
kbd.start!
