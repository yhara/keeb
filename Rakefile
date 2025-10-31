require 'fileutils'
QMK_DIR = File.expand_path("~/qmk_firmware")
TMP_DIR = File.expand_path("~/tmp/user_qmk")
MY_NAME = "yhara"

class Keyboard
  include FileUtils
  
  def initialize(name, path, url: nil, branch: "master", kb_path: nil, firmware_included: nil)
    @name, @path, @url, @branch, @firmware_included = name, path, url, branch, firmware_included
    @kb_path = kb_path || path.sub("keyboards/", "")
  end
  attr_reader :name, :path, :url, :kb_path

  def compile
    run_qmk("compile")
  end

  def flash
    run_qmk("flash")
  end
  
  def update
    return unless @url
	Dir.chdir(repo_dir(@name)) do
	  sh "git pull origin master"
	end
  end

  private

  # Execute `qmk xx`
  def run_qmk(subcommand)
    prepare_source
    sh "qmk #{subcommand} -kb #{@kb_path} -km #{MY_NAME}"
  end

  def prepare_source
    if @url
      copy_firmware_from_git(@url, @branch, @name)
    end
    if @firmware_included
      FileUtils.mkdir_p "#{QMK_DIR}/#{@path}"
      sh "cp -r #{@name}/* #{QMK_DIR}/#{@path}/"
    else
      FileUtils.mkdir_p "#{QMK_DIR}/#{@path}/keymaps/#{MY_NAME}"
      sh "cp -r #{@name}/* #{QMK_DIR}/#{@path}/keymaps/#{MY_NAME}"
    end
  end

  # Copy the firmware from git repository. Run `git clone` if not exists.
  def copy_firmware_from_git(url, branch, name)
    if !File.exist?(repo_dir(name))
      sh "git clone #{url} -b #{branch} #{repo_dir(name)}"
    end
    into = File.dirname "#{QMK_DIR}/#{@path}"
    mkdir_p into
	puts "cp_r \"#{repo_dir(name)}/#{@path}\", \"#{into}/\""
    cp_r "#{repo_dir(name)}/#{@path}", "#{into}/"
  end
  
  def repo_dir(name)
    "#{TMP_DIR}/#{name}"
  end

  def sh(cmd)
    puts cmd
    system cmd
  end
end

KEYBOARDS = [
  Keyboard.new("aleth42", "keyboards/25keys/aleth42"),
  Keyboard.new("bancouver40", "keyboards/sporewoh/bancouver40", url: "https://github.com/ChrisChrisLoLo/qmk_firmware/", branch: "bancouver40"),
  Keyboard.new("lesovoz", "keyboards/lesovoz",            url: "https://github.com/Tsquash/vial-qmk"),
  Keyboard.new("pi40",    "keyboards/1upkeyboards/pi40/", kb_path: "1upkeyboards/pi40/grid_v1_1"),
  Keyboard.new("sugarglider", "keyboards/mechwild/sugarglider"),
  Keyboard.new("cocot46plus", "keyboards/aki27/cocot46plus", url: "https://github.com/aki27kbd/qmk_firmware"),
  Keyboard.new("zinc", "keyboards/25keys/zinc"),
  Keyboard.new("bolt", "keyboards/lazydesigners/bolt"),
  Keyboard.new("daditto", "keyboards/yynmt/daditto", url: "https://github.com/yynmt/qmk_firmware/", branch: "daditto"),
  Keyboard.new("kagamidget", "keyboards/yynmt/kagamidget"),
  Keyboard.new("tata30", "keyboards/cerbekos/tata30", url: "https://github.com/Cerbekos/qmk_firmware/", branch: "v19_branch"),
  Keyboard.new("oceanographer", "keyboards/prototypist/oceanographer"),
  Keyboard.new("lmao", "keyboards/zicodia/tklfrlnrlmlao"),
  Keyboard.new("littol", "keyboards/littol", firmware_included: true),
  Keyboard.new("bruce", "keyboards/jlw/bruce_the_keyboard"),
  Keyboard.new("koneko40", "keyboards/lordsboards/koneko40_stagger", url: "https://github.com/hlord2000/vial-qmk/", branch: "koneko40"),
  # detour with bongocat patch (via 40% discord)
  Keyboard.new("detour", "keyboards/nachie/syndrome", url: "https://github.com/runty/vial-qmk/", branch: "vial"),
  #Keyboard.new("detour_nachie", "keyboards/nachie/syndrome", url: "https://github.com/nachie/vial-qmk/", branch: "nachie/syndrome"),
  Keyboard.new("gravity36", "keyboards/takashicompany/klec_02"),
  Keyboard.new("acai", "keyboards/quark_works/acai", url: "https://github.com/quark-works/vial-qmk/", branch: "qw-develop"),  
  Keyboard.new("amperconcrete", "keyboards/whitefacemountain/ampersand"),
  Keyboard.new("tightwriter", "keyboards/takashicompany/tightwriter"),
]

task :setup do
  mkdir_p TMP_DIR
end

KEYBOARDS.each do |keeb|
  desc "Compile '#{keeb.kb_path}'"
  task "#{keeb.name}_compile" do
    keeb.compile
  end

  desc "Compile and flash '#{keeb.kb_path}'"
  task "#{keeb.name}_flash" do
    keeb.flash
  end
  
  task "#{keeb.name}_update" do
    keeb.update
  end
end

#
# old
#

LINKS = {
  # firmware
  "user_qmk/Tsquash/keyboards/lesovoz" => "keyboards/lesovoz",
  "user_qmk/e3w2q/keyboards/e3w2q/kasumigasane" => "keyboards/kasumigasane",
  "user_qmk/aki27kbd/keyboards/cocot46plus" => "keyboards/cocot46plus",
  "user_qmk/ykz89/keyboards/cocot46plus" => "keyboards/ykz89",
  "user_qmk/yohewi/keyboards/kawaii10" => "keyboards/kawaii10",
  "kasumigasane/ez_maker" => "keyboards/ez_kasumi",
  # keymap
  "bolt" => "keyboards/lazydesigners/bolt/keymaps/yhara",
  "cocot46plus" => "keyboards/cocot46plus/keymaps/yhara",
  "lesovoz" => "keyboards/lesovoz/keymaps/yhara",
  "zinc" => "keyboards/25keys/zinc/keymaps/yhara",
  "kasumigasane/yhara" => "keyboards/kasumigasane/keymaps/yhara",
  "kawaii10" => "keyboards/kawaii10/keymaps/yhara",
}
desc "symlink"
task :link do
  LINKS.each do |src, dst|
    src_full = File.expand_path(src, "~/proj/keeb/")
    dst_full = File.expand_path(dst, "~/qmk_firmware/")
    if File.exist?(dst_full)
      puts "Already exists: #{dst_full}"
    else
      sh "ln -s #{src_full} #{dst_full}"
    end
  end
end

task default: :link

task :user_qmk do
  name = "ykz89"
  repo = "#{name}/qmk_firmware"
  branch = "cocot46plus"
  keeb_dir = "/keyboards/cocot46plus"
  #sh "git submodule add https://github.com/#{repo} user_qmk/#{name}"
  #sh "git -C user_qmk/#{name} config core.sparsecheckout true"
  sh "echo '#{keeb_dir}' >> .git/modules/user_qmk/#{name}/info/sparse-checkout"
  sh "git -C user_qmk/#{name} co #{branch}"
end

task :kasumi do
  cp "kasumigasane/keymap.rb", "/Volumes/PRKFirmware/"
end
