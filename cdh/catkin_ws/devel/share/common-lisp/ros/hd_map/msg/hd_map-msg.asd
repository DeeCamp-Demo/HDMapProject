
(cl:in-package :asdf)

(defsystem "hd_map-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sensor_msgs-msg
)
  :components ((:file "_package")
    (:file "element" :depends-on ("_package_element"))
    (:file "_package_element" :depends-on ("_package"))
    (:file "elements" :depends-on ("_package_elements"))
    (:file "_package_elements" :depends-on ("_package"))
  ))